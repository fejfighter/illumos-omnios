/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Copyright 2020 Tintri by DDN, Inc. All rights reserved.
 */

#include <sys/errno.h>
#include <string.h>
#include <strings.h>

#include <libmlrpc.h>

#define	NDR_DEFAULT_FRAGSZ	8192
#define	NDR_MULTI_FRAGSZ	(60 * 1024)

static void ndr_clnt_init_hdr(ndr_client_t *, ndr_xa_t *);
static int ndr_clnt_get_frags(ndr_client_t *, ndr_xa_t *);
static int ndr_clnt_get_frag(ndr_client_t *, ndr_xa_t *, ndr_common_header_t *);

int
ndr_clnt_bind(ndr_client_t *clnt, ndr_service_t *msvc,
    ndr_binding_t **ret_binding_p)
{
	ndr_binding_t		*mbind;
	ndr_xa_t		mxa;
	ndr_bind_hdr_t		*bhdr;
	ndr_common_header_t	*hdr;
	ndr_p_cont_elem_t	*pce;
	ndr_bind_ack_hdr_t	*bahdr;
	ndr_p_result_t		*pre;
	int			rc;

	bzero(&mxa, sizeof (mxa));

	mxa.binding_list = clnt->binding_list;
	if ((mbind = ndr_svc_new_binding(&mxa)) == NULL)
		return (NDR_DRC_FAULT_API_BIND_NO_SLOTS);

	ndr_clnt_init_hdr(clnt, &mxa);

	bhdr = &mxa.send_hdr.bind_hdr;
	hdr = &mxa.send_hdr.bind_hdr.common_hdr;
	hdr->ptype = NDR_PTYPE_BIND;
	bhdr->max_xmit_frag = NDR_DEFAULT_FRAGSZ;
	bhdr->max_recv_frag = NDR_DEFAULT_FRAGSZ;
	bhdr->assoc_group_id = 0;
	bhdr->p_context_elem.n_context_elem = 1;

	/* Assign presentation context id */
	pce = &bhdr->p_context_elem.p_cont_elem[0];
	pce->p_cont_id = clnt->next_p_cont_id++;
	pce->n_transfer_syn = 1;

	/* Set up UUIDs and versions from the service */
	pce->abstract_syntax.if_version = msvc->abstract_syntax_version;
	rc = ndr_uuid_parse(msvc->abstract_syntax_uuid,
	    &pce->abstract_syntax.if_uuid);
	if (rc != 0)
		return (NDR_DRC_FAULT_API_SERVICE_INVALID);

	pce->transfer_syntaxes[0].if_version = msvc->transfer_syntax_version;
	rc = ndr_uuid_parse(msvc->transfer_syntax_uuid,
	    &pce->transfer_syntaxes[0].if_uuid);
	if (rc != 0)
		return (NDR_DRC_FAULT_API_SERVICE_INVALID);

	/* Format and exchange the PDU */

	if ((*clnt->xa_init)(clnt, &mxa) < 0)
		return (NDR_DRC_FAULT_OUT_OF_MEMORY);

	/* Reserve room for hdr */
	mxa.send_nds.pdu_scan_offset = sizeof (*bhdr);

	/* GSS_Init_sec_context */
	rc = ndr_add_sec_context(&clnt->auth_ctx, &mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rc = ndr_encode_pdu_auth(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	/*
	 * If we have auth data, then pdu_size has been initialized.
	 * Otherwise, it hasn't.
	 */
	if (hdr->auth_length == 0)
		hdr->frag_length = sizeof (*bhdr);
	else
		hdr->frag_length = mxa.send_nds.pdu_size;

	/* Reset scan_offset to header */
	mxa.send_nds.pdu_scan_offset = 0;

	rc = ndr_encode_pdu_hdr(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	if ((*clnt->xa_exchange)(clnt, &mxa) < 0) {
		rc = NDR_DRC_FAULT_SEND_FAILED;
		goto fault_exit;
	}

	rc = ndr_decode_pdu_hdr(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rc = ndr_decode_pdu_auth(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	bahdr = &mxa.recv_hdr.bind_ack_hdr;

	if (mxa.ptype != NDR_PTYPE_BIND_ACK) {
		rc = NDR_DRC_FAULT_RECEIVED_MALFORMED;
		goto fault_exit;
	}

	if (bahdr->p_result_list.n_results != 1) {
		rc = NDR_DRC_FAULT_RECEIVED_MALFORMED;
		goto fault_exit;
	}

	pre = &bahdr->p_result_list.p_results[0];

	if (pre->result != NDR_PCDR_ACCEPTANCE) {
		rc = NDR_DRC_FAULT_RECEIVED_MALFORMED;
		goto fault_exit;
	}

	/* GSS_init_sec_context 2 */
	rc = ndr_recv_sec_context(&clnt->auth_ctx, &mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	/* done with buffers */
	(*clnt->xa_destruct)(clnt, &mxa);

	mbind->p_cont_id = pce->p_cont_id;
	mbind->which_side = NDR_BIND_SIDE_CLIENT;
	mbind->clnt = clnt;
	mbind->service = msvc;
	mbind->instance_specific = 0;

	*ret_binding_p = mbind;
	return (NDR_DRC_OK);

fault_exit:
	(*clnt->xa_destruct)(clnt, &mxa);
	return (rc);
}

int
ndr_clnt_call(ndr_binding_t *mbind, int opnum, void *params)
{
	ndr_client_t		*clnt = mbind->clnt;
	ndr_xa_t		mxa;
	ndr_request_hdr_t	*reqhdr;
	ndr_common_header_t	*rsphdr;
	unsigned long		recv_pdu_scan_offset, recv_pdu_size;
	int			rc;

	bzero(&mxa, sizeof (mxa));
	mxa.ptype = NDR_PTYPE_REQUEST;
	mxa.opnum = opnum;
	mxa.binding = mbind;

	ndr_clnt_init_hdr(clnt, &mxa);

	reqhdr = &mxa.send_hdr.request_hdr;
	reqhdr->common_hdr.ptype = NDR_PTYPE_REQUEST;
	reqhdr->p_cont_id = mbind->p_cont_id;
	reqhdr->opnum = opnum;

	rc = (*clnt->xa_init)(clnt, &mxa);
	if (NDR_DRC_IS_FAULT(rc))
		return (rc);

	/* Reserve room for hdr */
	mxa.send_nds.pdu_scan_offset = sizeof (*reqhdr);
	/* pdu_scan_offset now points to start of stub */
	mxa.send_nds.pdu_body_offset = mxa.send_nds.pdu_scan_offset;

	rc = ndr_encode_call(&mxa, params);
	if (!NDR_DRC_IS_OK(rc))
		goto fault_exit;

	/*
	 * With the Stub data encoded, calculate the alloc_hint
	 * before we add padding or auth data.
	 */
	reqhdr->alloc_hint = mxa.send_nds.pdu_size -
	    sizeof (ndr_request_hdr_t);

	/* GSS_WrapEx/VerifyMICEx */
	rc = ndr_add_auth(&clnt->auth_ctx, &mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rc = ndr_encode_pdu_auth(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	/*
	 * Now we have the PDU size, we need to set up the
	 * frag_length.
	 * Also reset pdu_scan_offset to header.
	 */
	mxa.send_hdr.common_hdr.frag_length = mxa.send_nds.pdu_size;
	mxa.send_nds.pdu_scan_offset = 0;

	rc = ndr_encode_pdu_hdr(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rc = (*clnt->xa_exchange)(clnt, &mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rc = ndr_decode_pdu_hdr(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	if (mxa.ptype != NDR_PTYPE_RESPONSE) {
		rc = NDR_DRC_FAULT_RECEIVED_MALFORMED;
		goto fault_exit;
	}

	rc = ndr_decode_pdu_auth(&mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rc = ndr_check_auth(&clnt->auth_ctx, &mxa);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	rsphdr = &mxa.recv_hdr.common_hdr;

	if (!NDR_IS_LAST_FRAG(rsphdr->pfc_flags)) {
		/*
		 * This is a multi-fragment response.
		 * Preserve the current body offset while getting
		 * fragments so that we can continue afterward
		 * as if we had received the entire response as
		 * a single PDU.
		 *
		 * GROW_PDU trashes pdu_size; reset it afterwards.
		 */
		recv_pdu_size = mxa.recv_nds.pdu_size;
		(void) NDS_GROW_PDU(&mxa.recv_nds, NDR_MULTI_FRAGSZ, NULL);

		/*
		 * pdu_scan_offset needs to be the first byte after the first
		 * fragment in pdu_base_addr (minus the sec_trailer).
		 *
		 * pdu_size needs to be all of the (usable) data we've
		 * received thus far.
		 */
		recv_pdu_scan_offset = mxa.recv_nds.pdu_body_offset;
		mxa.recv_nds.pdu_scan_offset = mxa.recv_nds.pdu_body_offset +
		    mxa.recv_nds.pdu_body_size - mxa.recv_auth.auth_pad_len;
		mxa.recv_nds.pdu_size = recv_pdu_size;

		rc = ndr_clnt_get_frags(clnt, &mxa);
		if (NDR_DRC_IS_FAULT(rc))
			goto fault_exit;

		mxa.recv_nds.pdu_scan_offset = recv_pdu_scan_offset;
	}

	rc = ndr_decode_return(&mxa, params);
	if (NDR_DRC_IS_FAULT(rc))
		goto fault_exit;

	(*clnt->xa_preserve)(clnt, &mxa);
	(*clnt->xa_destruct)(clnt, &mxa);
	return (NDR_DRC_OK);

fault_exit:
	ndr_show_hdr(&mxa.send_hdr.common_hdr);
	nds_show_state(&mxa.send_nds);
	if (mxa.send_hdr.common_hdr.auth_length != 0)
		ndr_show_auth(&mxa.send_auth);

	ndr_show_hdr(&mxa.recv_hdr.common_hdr);
	nds_show_state(&mxa.recv_nds);
	if (mxa.recv_hdr.common_hdr.auth_length != 0)
		ndr_show_auth(&mxa.recv_auth);
	(*clnt->xa_destruct)(clnt, &mxa);
	return (rc);
}

void
ndr_clnt_free_heap(ndr_client_t *clnt)
{
	(*clnt->xa_release)(clnt);
}

static void
ndr_clnt_init_hdr(ndr_client_t *clnt, ndr_xa_t *mxa)
{
	ndr_common_header_t *hdr = &mxa->send_hdr.common_hdr;

	hdr->rpc_vers = 5;
	hdr->rpc_vers_minor = 0;
	hdr->pfc_flags = NDR_PFC_FIRST_FRAG + NDR_PFC_LAST_FRAG;
	hdr->packed_drep.intg_char_rep = NDR_REPLAB_CHAR_ASCII;
#ifndef _BIG_ENDIAN
	hdr->packed_drep.intg_char_rep |= NDR_REPLAB_INTG_LITTLE_ENDIAN;
#endif
	/* hdr->frag_length */
	hdr->auth_length = 0;
	hdr->call_id = clnt->next_call_id++;
}

/*
 * ndr_clnt_get_frags
 *
 * A DCE RPC message that is larger than a single fragment is transmitted
 * as a series of fragments: 5280 bytes for Windows NT and 4280 bytes for
 * both Windows 2000 and 2003.
 *
 * Collect RPC fragments and append them to the receive stream buffer.
 * Each received fragment has a header, which we need to remove as we
 * build the full RPC PDU.  The scan offset is used to track frag headers.
 */
static int
ndr_clnt_get_frags(ndr_client_t *clnt, ndr_xa_t *mxa)
{
	ndr_stream_t *nds = &mxa->recv_nds;
	ndr_common_header_t hdr;
	int frag_size;
	int last_frag;
	int rc;

	do {
		if (ndr_clnt_get_frag(clnt, mxa, &hdr) < 0) {
			nds_show_state(nds);
			return (NDR_DRC_FAULT_RECEIVED_RUNT);
		}

		last_frag = NDR_IS_LAST_FRAG(hdr.pfc_flags);
		frag_size = hdr.frag_length;

		/*
		 * ndr_clnt_get_frag() doesn't change pdu_scan_offset.
		 */
		if (frag_size > (nds->pdu_size - nds->pdu_scan_offset)) {
			nds_show_state(nds);
			return (NDR_DRC_FAULT_RECEIVED_MALFORMED);
		}

		if (hdr.auth_length != 0 && hdr.auth_length >
		    (hdr.frag_length - nds->pdu_hdr_size - SEC_TRAILER_SIZE))
			return (NDR_DRC_FAULT_RECEIVED_MALFORMED);

		rc = ndr_decode_pdu_auth(mxa);
		if (NDR_DRC_IS_FAULT(rc))
			return (rc);

		rc = ndr_check_auth(&clnt->auth_ctx, mxa);
		if (NDR_DRC_IS_FAULT(rc))
			return (rc);

		/*
		 * Headers, Auth Padding, and auth data shouldn't be kept
		 * from fragments.
		 */
		ndr_remove_frag_hdr(nds);
		nds->pdu_scan_offset +=
		    nds->pdu_body_size - mxa->recv_auth.auth_pad_len;
	} while (!last_frag);

	return (0);
}

/*
 * Read the next RPC fragment.  The xa_read() calls correspond to SmbReadX
 * requests.  Note that there is no correspondence between SmbReadX buffering
 * and DCE RPC fragment alignment.
 */
static int
ndr_clnt_get_frag(ndr_client_t *clnt, ndr_xa_t *mxa, ndr_common_header_t *hdr)
{
	ndr_stream_t		*nds = &mxa->recv_nds;
	unsigned long		available;
	int			nbytes = 0;

	available = nds->pdu_size - nds->pdu_scan_offset;

	while (available < NDR_RSP_HDR_SIZE) {
		if ((nbytes = (*clnt->xa_read)(clnt, mxa)) <= 0)
			return (-1);
		available += nbytes;
	}

	ndr_decode_frag_hdr(nds, hdr);
	ndr_show_hdr(hdr);

	while (available < hdr->frag_length) {
		if ((nbytes = (*clnt->xa_read)(clnt, mxa)) <= 0)
			return (-1);
		available += nbytes;
	}

	return (nbytes);
}
