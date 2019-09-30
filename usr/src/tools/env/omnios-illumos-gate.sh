
######################################################################
# OmniOS-specific overrides

# Enable the non-DEBUG build
NIGHTLY_OPTIONS=${NIGHTLY_OPTIONS/F/}

export PERL_VERSION=5.28
export PERL_PKGVERS=
export PERL_VARIANT=-thread-multi
# This next line is needed to build a pre-7661 gate and does no harm post 7661
export PERL_ARCH=i86pc-solaris-thread-multi-64int

export JAVA_ROOT=/usr/jdk/openjdk1.8.0
export JAVA_HOME=$JAVA_ROOT
export BLD_JAVA_7='#'
export BLD_JAVA_8=

export BUILDPY2=
export BUILDPY3=
export BUILDPY2TOOLS=
export BUILDPY3TOOLS=
export TOOLS_PYTHON=/usr/bin/python3.5

export GNUC_ROOT=/opt/gcc-7/
export ON_CLOSED_BINS=/opt/onbld/closed

# On OmniOS, gcc resides in /opt/gcc-<version> - adjust variables
export GNUC_ROOT=/opt/gcc-7/
for name in PRIMARY_CC PRIMARY_CCC SHADOW_CCS SHADOW_CCCS; do
        typeset -n var=$name
        var="`echo $var | sed '
                s^/usr/^/opt/^
                s^/opt/gcc/^/opt/gcc-^
        '`"
done

ENABLE_SMB_PRINTING='#'

export ONNV_BUILDNUM=`grep '^VERSION=r' /etc/os-release | cut -c10-15`
export PKGVERS_BRANCH=$ONNV_BUILDNUM.0

