/*
 * Copyright 2014-2017 Cavium, Inc.
 * The contents of this file are subject to the terms of the Common Development
 * and Distribution License, v.1,  (the "License").
 *
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the License at available
 * at http://opensource.org/licenses/CDDL-1.0
 *
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 4.0.4 */
#include "bcmtype.h"
int   TPAT_b06FwReleaseMajor = 0x1;
int   TPAT_b06FwReleaseMinor = 0x0;
int   TPAT_b06FwReleaseFix = 0x0;
u32_t TPAT_b06FwStartAddr = 0x08000490;
u32_t TPAT_b06FwTextAddr = 0x08000400;
int   TPAT_b06FwTextLen = 0x17d4;
u32_t TPAT_b06FwDataAddr = 0x00000000;
int   TPAT_b06FwDataLen = 0x0;
u32_t TPAT_b06FwRodataAddr = 0x00000000;
int   TPAT_b06FwRodataLen = 0x0;
u32_t TPAT_b06FwBssAddr = 0x08001c44;
int   TPAT_b06FwBssLen = 0x450;
u32_t TPAT_b06FwSbssAddr = 0x08001c00;
int   TPAT_b06FwSbssLen = 0x44;
u32_t TPAT_b06FwSDataAddr = 0x00000000;
int   TPAT_b06FwSDataLen = 0x0;
u32_t TPAT_b06FwText[(0x17d4/4) + 1] = {
0xa000124, 
0x0, 0x0, 0xd, 0x74706136, 
0x2e322e33, 0x0, 0x6020301, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 
0x10000003, 0x0, 0xd, 0xd, 
0x3c020800, 0x24421c00, 0x3c030800, 0x24632094, 
0xac400000, 0x43202b, 0x1480fffd, 0x24420004, 
0x3c1d0800, 0x37bd2ffc, 0x3a0f021, 0x3c100800, 
0x26100490, 0x3c1c0800, 0x279c1c00, 0xe00015c, 
0x0, 0xd, 0x3084ffff, 0x30820007, 
0x8f850018, 0x10400002, 0x24830007, 0x3064fff8, 
0x853021, 0x30c41fff, 0x3441821, 0x247b4000, 
0xaf85001c, 0xaf840018, 0x3e00008, 0xaf440084, 
0x3084ffff, 0x30820007, 0x8f850020, 0x8f860028, 
0x10400002, 0x24830007, 0x3064fff8, 0x852021, 
0x86182b, 0x14600002, 0xaf850024, 0x862023, 
0x3442821, 0x34068000, 0xaf840020, 0xaf440080, 
0xa62021, 0x3e00008, 0xaf840038, 0x27bdffd8, 
0xafb3001c, 0xafb20018, 0xafb00010, 0xafbf0024, 
0xafb40020, 0xafb10014, 0x3c086008, 0x8d145000, 
0x2418ff7f, 0x3c1a8000, 0x2989824, 0x3672380c, 
0xad125000, 0x8f510008, 0x3c07601c, 0x3c086000, 
0x36300001, 0xaf500008, 0xaf800018, 0xaf400080, 
0xaf400084, 0x8ce60008, 0x8d0f0808, 0x3c076016, 
0x8cec0000, 0x31eefff0, 0x39ca0010, 0x3c0dffff, 
0x340b8000, 0x3c030080, 0x34b4821, 0x2d440001, 
0x18d2824, 0x3c025353, 0x3c010800, 0xac230420, 
0xaf890038, 0xaf860028, 0xaf840010, 0x275b4000, 
0x14a20003, 0x34e37c00, 0x8cf90004, 0x3281821, 
0x8c7f007c, 0x8c650078, 0x3c028000, 0x3c0b0800, 
0x8d6b048c, 0x3c0a0800, 0x8d4a0488, 0x34520070, 
0xaf85003c, 0xaf9f0040, 0x3c130800, 0x26731c44, 
0x240a021, 0x8e480000, 0x8f460000, 0x38c30001, 
0x30640001, 0x10800017, 0xaf880034, 0x2804821, 
0x8d2f0000, 0x3c050800, 0x8ca5045c, 0x3c180800, 
0x8f180458, 0x1e81023, 0xa28021, 0xc821, 
0x202402b, 0x3198821, 0x2283821, 0x3c010800, 
0xac30045c, 0x3c010800, 0xac270458, 0x8f4e0000, 
0x39cd0001, 0x31ac0001, 0x1580ffed, 0x1e04021, 
0xaf8f0034, 0x8e510000, 0x3c070800, 0x8ce7045c, 
0x3c0d0800, 0x8dad0458, 0x2288023, 0xf06021, 
0x7021, 0x190302b, 0x1ae1821, 0x662021, 
0x3c010800, 0xac2c045c, 0x3c010800, 0xac240458, 
0x8f460108, 0x8f470100, 0x30c92000, 0xaf860000, 
0xaf87000c, 0x1120000a, 0xc04021, 0x3c180800, 
0x8f18042c, 0x27080001, 0x3c010800, 0xac28042c, 
0x3c184000, 0xaf580138, 0xa000196, 0x0, 
0x97490104, 0x2821, 0x1455021, 0x3122ffff, 
0x1625821, 0x162f82b, 0x15f5021, 0x30d90200, 
0x3c010800, 0xac2b048c, 0x3c010800, 0xac2a0488, 
0x17200015, 0x24040f00, 0x10e40013, 0x0, 
0x24080d00, 0x10e8023b, 0x30cd0006, 0x11a0ffe9, 
0x3c184000, 0x936e0000, 0x24090010, 0x31c400f0, 
0x10890271, 0x24020070, 0x108202e5, 0x8f880014, 
0x250f0001, 0xaf8f0014, 0x3c184000, 0xaf580138, 
0xa000196, 0x0, 0x974c0104, 0x1180ffd9, 
0x3c184000, 0x30c34000, 0x146000a1, 0x0, 
0x8f460178, 0x4c0fffe, 0x8f870038, 0x24100800, 
0x240f0008, 0x8ce30008, 0xaf500178, 0xa74f0140, 
0xa7400142, 0x974e0104, 0x8f860000, 0x31c9ffff, 
0x30cd0001, 0x11a002e1, 0x1204021, 0x2531fffe, 
0x24180002, 0xa7580146, 0x3228ffff, 0xa7510148, 
0x3c190800, 0x8f39043c, 0x172002d0, 0x8f8c000c, 
0x30df0020, 0x17e00002, 0x24040009, 0x24040001, 
0x30c20c00, 0x24050400, 0x50450001, 0x34840004, 
0xa744014a, 0x3c110800, 0x8e310420, 0x3c180048, 
0x3c100001, 0x2381825, 0x30cf0002, 0x702825, 
0x11e00004, 0x1821, 0x3c190100, 0xb92825, 
0x24030001, 0x30df0004, 0x53e00005, 0xaf830008, 
0x3c060010, 0xa62825, 0x24030001, 0xaf830008, 
0xaf451000, 0x0, 0x0, 0x0, 
0x0, 0x8f830008, 0x10600023, 0x0, 
0x8f451000, 0x4a1fffe, 0x0, 0x1060001e, 
0x0, 0x8f441000, 0x3c0c0020, 0x8c1024, 
0x10400019, 0x8f8e0000, 0x31cd0002, 0x11a00016, 
0x0, 0x974f1014, 0x15e00013, 0x0, 
0x97591008, 0x3338ffff, 0x27110006, 0x111882, 
0x33080, 0xc72821, 0x32300001, 0x32230003, 
0x1200032c, 0x8ca20000, 0xd, 0xc7f821, 
0xafe20000, 0x3c050800, 0x8ca50430, 0x24a60001, 
0x3c010800, 0xac260430, 0x8f6d0000, 0x3402ffff, 
0xaf8d0004, 0x8cec0000, 0x118202a6, 0x2021, 
0x8ced0000, 0x31ac0100, 0x1180028a, 0x0, 
0x3c020800, 0x8c420474, 0x3c030800, 0x8c63044c, 
0x3c1f0800, 0x8fff0470, 0x3c180800, 0x8f180448, 
0x483821, 0x688021, 0xe8282b, 0x3e43021, 
0x208402b, 0x3048821, 0xc57021, 0x2287821, 
0x3c010800, 0xac30044c, 0x3c010800, 0xac2f0448, 
0x3c010800, 0xac270474, 0x3c010800, 0xac2e0470, 
0x8f840018, 0x1203021, 0x31290007, 0x249f0008, 
0x33f91fff, 0x3594021, 0xaf84001c, 0xaf990018, 
0x251b4000, 0xaf590084, 0x11200003, 0x8f830020, 
0x24c20007, 0x3046fff8, 0x8f840028, 0xc32821, 
0xa4302b, 0x14c00002, 0xaf830024, 0xa42823, 
0x3456021, 0x340d8000, 0x18d1021, 0x3c0f1000, 
0xaf850020, 0xaf820038, 0xaf450080, 0xaf4f0178, 
0x8f880014, 0x250f0001, 0xa0001ef, 0xaf8f0014, 
0x8f620008, 0x8f670000, 0x24050030, 0x77602, 
0x31c300f0, 0x106500a7, 0x240f0040, 0x546fff4c, 
0x8f880014, 0x8f4b0178, 0x560fffe, 0x0, 
0x30ca0200, 0x15400003, 0x61282, 0xd, 
0x61282, 0x304d0003, 0xd4900, 0x12d1821, 
0x38080, 0x20d4021, 0x86080, 0x1938021, 
0x8e1f0000, 0x17e00002, 0x0, 0xd, 
0x8f6e0004, 0x5c202bd, 0x92070006, 0x920e0005, 
0x92020004, 0x3c090001, 0xe1880, 0x70f821, 
0x8fed0018, 0x27710008, 0x24480005, 0x1a96021, 
0x83082, 0xafec0018, 0x2202021, 0xe00059e, 
0x26050014, 0x920a0006, 0x8f790004, 0x3c0b7fff, 
0xa2080, 0x917821, 0x8df80004, 0x3566ffff, 
0x3262824, 0x3053821, 0xade70004, 0x920e0005, 
0x920d0004, 0x960c0008, 0xe1080, 0x51c821, 
0x8f230000, 0x97490104, 0x3c07ffff, 0x675824, 
0x3128ffff, 0x10df821, 0x3ec5023, 0x3144ffff, 
0x1643025, 0xaf260000, 0x92030007, 0x24180001, 
0x10780275, 0x240f0003, 0x106f0285, 0x0, 
0x8e050010, 0x2419000a, 0xa7590140, 0xa7450142, 
0x92180004, 0x8f860000, 0x240f0001, 0xa7580144, 
0xa7400146, 0x97470104, 0x30d10002, 0x3c050041, 
0xa7470148, 0x1821, 0xa74f014a, 0x12200003, 
0x30cb0004, 0x3c050141, 0x24030001, 0x51600005, 
0xaf830008, 0x3c060010, 0xa62825, 0x24030001, 
0xaf830008, 0xaf451000, 0x0, 0x0, 
0x0, 0x0, 0x8f8a0008, 0x11400004, 
0x0, 0x8f441000, 0x481fffe, 0x0, 
0x8f6b0000, 0x92080004, 0x3c110800, 0x8e310444, 
0xaf8b0004, 0x97590104, 0x311800ff, 0x3c0e0800, 
0x8dce0440, 0x3325ffff, 0x3053821, 0x2276021, 
0x1021, 0x250f000a, 0x31e8ffff, 0x187482b, 
0x1c26821, 0x1a9f821, 0x31100007, 0x3c010800, 
0xac2c0444, 0x3c010800, 0xac3f0440, 0x12000003, 
0x8f8c0018, 0x25060007, 0x30c8fff8, 0x10c6821, 
0x31bf1fff, 0xaf8c001c, 0xaf9f0018, 0xaf5f0084, 
0x97440104, 0x35f8021, 0x3084ffff, 0x308a0007, 
0x11400003, 0x261b4000, 0x24890007, 0x3124fff8, 
0x8f820020, 0x8f850028, 0x822021, 0x85702b, 
0x15c00002, 0xaf820024, 0x852023, 0x3c0b0800, 
0x8d6b048c, 0x3c0a0800, 0x8d4a0488, 0x3448821, 
0x34038000, 0x2231021, 0x3c0f1000, 0xaf840020, 
0xaf820038, 0xaf440080, 0xaf4f0178, 0xa000296, 
0x8f880014, 0x8f500178, 0x600fffe, 0x30d10200, 
0x16200003, 0x61282, 0xd, 0x61282, 
0x305f0003, 0x1f1900, 0x7f3021, 0x62080, 
0x9fc821, 0x194880, 0x1338021, 0x8e180000, 
0x13000002, 0x0, 0xd, 0x8f6c000c, 
0x58001fb, 0x8f870038, 0x240e0001, 0xae0e0000, 
0x8ce30008, 0xa2000007, 0x8f650004, 0x55402, 
0x314d00ff, 0x25a80005, 0x83082, 0x2ccb0041, 
0x15600002, 0xa20a0004, 0xd, 0x8f780004, 
0x3c03ffff, 0xe02821, 0x330bffff, 0x256c000b, 
0xc1082, 0x22080, 0x874821, 0x8d3f0000, 
0x26040014, 0xa6180008, 0x3e3c824, 0xe00059e, 
0xad390000, 0x8f4f0108, 0x3c111000, 0x1f13824, 
0x10e001ab, 0x0, 0x974d0104, 0x92080007, 
0x25aaffec, 0x35060002, 0x3144ffff, 0xa2060007, 
0x96060008, 0x2cc70013, 0x54e00005, 0x92030007, 
0x92110007, 0x362f0001, 0xa20f0007, 0x92030007, 
0x24180001, 0x107801c2, 0x24090003, 0x106901d5, 
0x8f880038, 0x30cbffff, 0x25710002, 0x117883, 
0x31e400ff, 0x42880, 0xa20f0005, 0xa84821, 
0x8d2d0000, 0x974a0104, 0x3c0effff, 0x1aef824, 
0x3143ffff, 0x6b1023, 0x244cfffe, 0x3ecc825, 
0xad390000, 0x92060005, 0x3c03fff6, 0x3462ffff, 
0x30d800ff, 0x183880, 0xf08821, 0x922f0014, 
0x3c04ff7f, 0x3487ffff, 0x31ee000f, 0x1c65821, 
0x316500ff, 0x55080, 0x1506821, 0x8dac0020, 
0x148f821, 0xa20b0006, 0x182c824, 0xae0c000c, 
0xaff9000c, 0x92090006, 0x8e11000c, 0x3277824, 
0x9c080, 0x3107021, 0x95c60026, 0x3082821, 
0x2272024, 0xae04000c, 0xadcf0020, 0xadc60024, 
0xaca60010, 0x8f880000, 0x3c0b0800, 0x8d6b048c, 
0x3c0a0800, 0x8d4a0488, 0x241f0010, 0x24190002, 
0xa75f0140, 0xa7400142, 0xa7400144, 0xa7590146, 
0x97490104, 0x24070001, 0x31060002, 0x2538fffe, 
0xa7580148, 0x3c050009, 0xa747014a, 0x10c00003, 
0x1821, 0x3c050109, 0x24030001, 0x310c0004, 
0x51800005, 0xaf830008, 0x3c080010, 0xa82825, 
0x24030001, 0xaf830008, 0xaf451000, 0x0, 
0x0, 0x0, 0x0, 0x92050004, 
0x24ae0002, 0x31cd0007, 0xd1823, 0x30620007, 
0xae020010, 0x8f900008, 0x12000004, 0x0, 
0x8f4f1000, 0x5e1fffe, 0x0, 0x8f710000, 
0x8f8e0018, 0x3c030800, 0x8c630444, 0xaf910004, 
0x97450104, 0x25cf0010, 0x31e61fff, 0x30a2ffff, 
0xaf8e001c, 0xaf860018, 0xaf460084, 0x2449fffe, 
0x3c0c0800, 0x8d8c0440, 0x974d0104, 0x1208021, 
0x947c3, 0x70c021, 0x31a9ffff, 0x310f82b, 
0x188c821, 0x33f2021, 0x3463821, 0x31310007, 
0x3c010800, 0xac380444, 0x3c010800, 0xac240440, 
0x12200003, 0x24fb4000, 0x25270007, 0x30e9fff8, 
0x8f860020, 0x8f840028, 0x1263821, 0xe4c02b, 
0x17000002, 0xaf860024, 0xe43823, 0x3472021, 
0x34198000, 0x991021, 0x3c0f1000, 0xaf870020, 
0xaf820038, 0xaf470080, 0xaf4f0178, 0xa000296, 
0x8f880014, 0x97470104, 0x10e0fdae, 0x3c184000, 
0x8f580178, 0x700fffe, 0x30c54000, 0x10a00003, 
0x3c1f0008, 0xd, 0x3c1f0008, 0xaf5f0140, 
0x24100800, 0x8f860000, 0xaf500178, 0x97440104, 
0x30d90001, 0x132000ed, 0x3086ffff, 0x24ccfffe, 
0x240d0002, 0xa74d0146, 0xa74c0148, 0x8f910018, 
0x2408000d, 0xa748014a, 0x8f630000, 0x262f0008, 
0x31e21fff, 0x3427021, 0x30c90007, 0xaf830004, 
0xaf91001c, 0xaf820018, 0xc03821, 0xaf420084, 
0x11200003, 0x25db4000, 0x24d80007, 0x3307fff8, 
0x8f850020, 0x8f840028, 0xe53021, 0xc4382b, 
0x14e00002, 0xaf850024, 0xc43023, 0x8f840014, 
0x346f821, 0x340c8000, 0xaf860020, 0x3ec8021, 
0xaf460080, 0x24990001, 0x3c061000, 0x3c184000, 
0xaf460178, 0xaf900038, 0xaf990014, 0xaf580138, 
0xa000196, 0x0, 0x8f630000, 0x97510104, 
0x3067ffff, 0x3228ffff, 0x8f4f0178, 0x5e0fffe, 
0x30ec0007, 0xcf823, 0x33f00007, 0x24f9fffe, 
0x2404000a, 0xa7440140, 0xa7500142, 0xa7590144, 
0xa7400146, 0xa7480148, 0x8f450108, 0x30b80020, 
0x17000002, 0x24030009, 0x24030001, 0x30cd0002, 
0xa743014a, 0x3c040041, 0x11a00003, 0x1821, 
0x3c040141, 0x24030001, 0x30c90004, 0x51200005, 
0xaf830008, 0x3c060010, 0x862025, 0x24030001, 
0xaf830008, 0xaf441000, 0x0, 0x0, 
0x0, 0x0, 0x8f8e0008, 0x11c00004, 
0x0, 0x8f421000, 0x441fffe, 0x0, 
0x8f7f0000, 0x27640008, 0x8f91003c, 0xaf9f0004, 
0x94850008, 0x9490000a, 0x9499000c, 0x30afffff, 
0x10c400, 0x3323ffff, 0x11f100a6, 0x3032025, 
0x3c0e0800, 0x8dce0444, 0x3c0c0800, 0x8d8c0440, 
0xe88821, 0x2626fffe, 0x1c62821, 0x6821, 
0xa6f82b, 0x18d2021, 0x9f8021, 0x3c010800, 
0xac250444, 0x3c010800, 0xac300440, 0x24e20008, 
0x3042ffff, 0x30470007, 0x10e00003, 0x8f830018, 
0x244f0007, 0x31e2fff8, 0x3106ffff, 0x30c80007, 
0x438021, 0x32191fff, 0x359c021, 0xaf83001c, 
0xaf990018, 0x271b4000, 0xaf590084, 0x11000003, 
0x8f8c0020, 0x24c50007, 0x30a6fff8, 0x8f840028, 
0xcc2821, 0xa4f82b, 0x17e00002, 0xaf8c0024, 
0xa42823, 0xaf850020, 0xaf450080, 0x3c040800, 
0x8c840434, 0x3454821, 0x340e8000, 0x12e6821, 
0x10800005, 0xaf8d0038, 0x93910017, 0x2406000e, 
0x12260011, 0x2407043f, 0x3c021000, 0xaf420178, 
0x8f880014, 0x250f0001, 0xa0001ef, 0xaf8f0014, 
0xe0005c4, 0xe02021, 0x8f880014, 0x3c0b0800, 
0x8d6b048c, 0x3c0a0800, 0x8d4a0488, 0x250f0001, 
0xa0001ef, 0xaf8f0014, 0x3c021000, 0xa7470148, 
0xaf420178, 0xa0004ce, 0x8f880014, 0x24040f00, 
0x1184003d, 0x30ce0020, 0x15c00002, 0x24030009, 
0x24030001, 0xa00021a, 0xa743014a, 0xa00020d, 
0xa7400146, 0x94ef0008, 0x94f1000a, 0x94f0000c, 
0x8f8c003c, 0x117400, 0x3207ffff, 0x31edffff, 
0x11ac0037, 0x1c72025, 0x3c180800, 0x8f180444, 
0x3c0f0800, 0x8def0440, 0x8021, 0x3086821, 
0x1a8382b, 0x1f07021, 0x1c76021, 0x3c010800, 
0xac2d0444, 0x3c010800, 0xac2c0440, 0xa00027a, 
0x8f840018, 0x3c020800, 0x8c42047c, 0x3c030800, 
0x8c630454, 0x3c1f0800, 0x8fff0478, 0x3c180800, 
0x8f180450, 0x483821, 0x688021, 0xe8282b, 
0x3e43021, 0x208402b, 0x3048821, 0xc57021, 
0x2287821, 0x3c010800, 0xac300454, 0x3c010800, 
0xac2f0450, 0x3c010800, 0xac27047c, 0x3c010800, 
0xac2e0478, 0xa00027a, 0x8f840018, 0xa7400146, 
0xa000435, 0x8f910018, 0x30cd0020, 0x15a0ffc5, 
0x2403000d, 0x24030005, 0xa00021a, 0xa743014a, 
0x974e0104, 0x25c5fff0, 0xa000381, 0x30a4ffff, 
0x8f980040, 0x1498ffc8, 0x1021, 0x3c050800, 
0x8ca5046c, 0x3c1f0800, 0x8fff0468, 0xa8c821, 
0x328302b, 0x3e22021, 0x864021, 0x3c010800, 
0xac39046c, 0x3c010800, 0xac280468, 0xa00027a, 
0x8f840018, 0x8f8c0040, 0x148cff59, 0xe8c821, 
0x3c180800, 0x8f18046c, 0x3c110800, 0x8e310468, 
0x2723fffe, 0x3034821, 0x1021, 0x123302b, 
0x2227021, 0x1c66821, 0x3c010800, 0xac29046c, 
0x3c010800, 0xac2d0468, 0xa0004a5, 0x24e20008, 
0x8f880038, 0x3c03ffff, 0x8d02000c, 0x43f824, 
0x3e4c825, 0xad19000c, 0xa00038f, 0x30cbffff, 
0xa0003c3, 0xae000000, 0x974a0104, 0x92040004, 
0x8e26000c, 0x1445821, 0x2579fff2, 0xc7c024, 
0x3325ffff, 0x3053825, 0xae27000c, 0xa0002e6, 
0x8e050010, 0x3c0dffff, 0x8d0a0010, 0x14d5824, 
0x1646025, 0xad0c0010, 0xa00038f, 0x30cbffff, 
0x97430104, 0x920e0004, 0x8e290010, 0x6e1021, 
0x244dffee, 0x1276024, 0x31a8ffff, 0x188f825, 
0xae3f0010, 0xa0002e6, 0x8e050010, 0x8e0f000c, 
0xae000000, 0x78880, 0x2302821, 0xa0002b8, 
0xacaf0020, 0x1460000d, 0x3058ffff, 0x3c04ffff, 
0x446824, 0x1a47026, 0xe602b, 0xd102b, 
0x4cf824, 0x13e00002, 0x0, 0xd, 
0x8caf0000, 0xa000250, 0x1e41025, 0x3b03ffff, 
0x3882b, 0x18802b, 0x2112024, 0x10800002, 
0x0, 0xd, 0x8cb90000, 0xa000250, 
0x3722ffff, 0x3084ffff, 0x30a5ffff, 0x10800007, 
0x1821, 0x30820001, 0x10400002, 0x42042, 
0x651821, 0x1480fffb, 0x52840, 0x3e00008, 
0x601021, 0x10c00007, 0x0, 0x8ca20000, 
0x24c6ffff, 0x24a50004, 0xac820000, 0x14c0fffb, 
0x24840004, 0x3e00008, 0x0, 0x10a00008, 
0x24a3ffff, 0xac860000, 0x0, 0x0, 
0x2402ffff, 0x2463ffff, 0x1462fffa, 0x24840004, 
0x3e00008, 0x0, 0x308effff, 0x30d8ffff, 
0x57c00, 0x1f86025, 0x39cdffff, 0x1ac5021, 
0x14c582b, 0x14b4821, 0x94402, 0x3127ffff, 
0xe83021, 0x62402, 0x30c5ffff, 0xa41821, 
0x3862ffff, 0x3e00008, 0x3042ffff, 0x3c0c0800, 
0x8d8c0484, 0x240bff80, 0x27bdffd0, 0x1845021, 
0x14b4824, 0xaf490020, 0x3c080800, 0x8d080484, 
0xafb20020, 0xafb00018, 0xafbf0028, 0xafb30024, 
0xafb1001c, 0x93660004, 0x1043821, 0x30e4007f, 
0x9a1021, 0x3c030008, 0x439021, 0x30c50020, 
0x3608021, 0x3c080111, 0x277b0008, 0x14a00002, 
0x26460070, 0x2646006c, 0x92130004, 0x97510104, 
0x920f0004, 0x3267000f, 0x322effff, 0x31ed0040, 
0x1c72823, 0x11a00005, 0x4821, 0x925900bc, 
0x33380004, 0x17000090, 0x0, 0x924300bc, 
0x307f0004, 0x13e0000f, 0x0, 0x10a0000d, 
0x0, 0x960e0002, 0x240aff80, 0xa76021, 
0x25cdfffe, 0xa74d1016, 0x920b0004, 0x14b2024, 
0x308200ff, 0x10400085, 0x10c4025, 0x3c0f0400, 
0x10f4025, 0x8f530178, 0x660fffe, 0x2404000a, 
0xa7440140, 0x960d0002, 0x24040009, 0x31ac0007, 
0xc5823, 0x316a0007, 0xa74a0142, 0x96020002, 
0x2443fffe, 0xa7430144, 0xa7400146, 0x975f0104, 
0xa75f0148, 0x8f590108, 0x33380020, 0x53000001, 
0x24040001, 0x920f0004, 0x31ee0010, 0x15c00002, 
0x34830010, 0x801821, 0xa743014a, 0x0, 
0x0, 0x0, 0x0, 0xaf481000, 
0x0, 0x0, 0x0, 0x0, 
0x8f511000, 0x621fffe, 0x3113ffff, 0x12600003, 
0x0, 0x8f481018, 0xacc80000, 0x96030006, 
0x307fffff, 0x27f90002, 0x199882, 0x138880, 
0x23b3021, 0x8cd80000, 0x15200057, 0x183402, 
0x92030004, 0x2405ff80, 0xa3f824, 0x33f100ff, 
0x1220002c, 0x0, 0x924700bc, 0x30f20002, 
0x12400028, 0x0, 0x974b100c, 0x2562fffe, 
0xa7421016, 0x0, 0x3c0a0400, 0x35490030, 
0xaf491000, 0x0, 0x0, 0x0, 
0x0, 0x8f4c1000, 0x581fffe, 0x0, 
0x9749100c, 0x8f51101c, 0xc02021, 0x3127ffff, 
0x24f20030, 0x121882, 0x32880, 0xbbf821, 
0x3226ffff, 0xaff10000, 0xe0005b3, 0x112c02, 
0x13c880, 0x33b9821, 0x8e780000, 0x27400, 
0xafb80010, 0x8fa80010, 0x310fffff, 0xafaf0010, 
0x8fa40010, 0x1c46825, 0xafad0010, 0x8fa60010, 
0xae660000, 0x97730008, 0x976d000a, 0x9766000c, 
0x8f8a003c, 0xd5c00, 0x30ccffff, 0x3262ffff, 
0x104a0036, 0x16c2025, 0x96060002, 0x3c101000, 
0x24d30008, 0xe00013b, 0x3264ffff, 0x974c0104, 
0xe000149, 0x3184ffff, 0xaf500178, 0x8fbf0028, 
0x8fb30024, 0x8fb20020, 0x8fb1001c, 0x8fb00018, 
0x3e00008, 0x27bd0030, 0x10a0ff70, 0x0, 
0x24a5fffc, 0xa0005ec, 0x24090004, 0x8cd10000, 
0xaf511018, 0x8f530178, 0x660ff7a, 0x2404000a, 
0xa000601, 0x0, 0xa7c821, 0x8f880038, 
0x8f4e101c, 0x19c082, 0x187880, 0x1e82021, 
0xac8e0000, 0xe2c02, 0xc02021, 0xe0005b3, 
0x31c6ffff, 0x23b2821, 0x8cad0000, 0x25400, 
0x403021, 0xafad0010, 0x8fac0010, 0x318bffff, 
0xafab0010, 0x8fa20010, 0x1424825, 0xafa90010, 
0x8fa70010, 0xa000631, 0xaca70000, 0x8f8f0040, 
0x148fffc9, 0x0, 0x97420104, 0x960b0002, 
0x3c050800, 0x8ca5046c, 0x3049ffff, 0x316affff, 
0x3c110800, 0x8e310468, 0x12a3821, 0x24f2fffe, 
0xb24021, 0x12ffc3, 0x112c82b, 0x23fc021, 
0x3192021, 0x3c010800, 0xac28046c, 0x3c010800, 
0xac240468, 0xa00066b, 0x0, 0xa4102b, 
0x10400009, 0x24030001, 0x52840, 0xa4102b, 
0x4a00003, 0x31840, 0x5440fffc, 0x52840, 
0x10600007, 0x0, 0x85302b, 0x14c00002, 
0x31842, 0x852023, 0x1460fffb, 0x52842, 
0x3e00008, 0x801021, 0x8f85002c, 0x27bdffe8, 
0x53027, 0x2cc30001, 0x2ca40002, 0x831025, 
0x10400003, 0xafbf0010, 0x2405007f, 0xaf85002c, 
0x52827, 0x30a5ffff, 0xe000592, 0x240426f5, 
0x8f830030, 0x240402bd, 0x403021, 0x83382b, 
0x10e00009, 0x24050001, 0x42040, 0x83102b, 
0x4800003, 0x52840, 0x5440fffc, 0x42040, 
0x10a00008, 0xc35021, 0x64402b, 0x15000002, 
0x52842, 0x641823, 0x14a0fffb, 0x42042, 
0xc35021, 0x8fbf0010, 0xa4c02, 0x312200ff, 
0x27bd0018, 0xaf8a002c, 0x3e00008, 0xaf890030, 
0x0 };
u32_t TPAT_b06FwData[(0x0/4) + 1] = { 0x0 };
u32_t TPAT_b06FwRodata[(0x0/4) + 1] = { 0x0 };
u32_t TPAT_b06FwBss[(0x450/4) + 1] = { 0x0 };
u32_t TPAT_b06FwSbss[(0x44/4) + 1] = { 0x0 };
u32_t TPAT_b06FwSdata[(0x0/4) + 1] = { 0x0 };
