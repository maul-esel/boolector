#!/bin/sh

die () {
   echo "*** mkconfig.sh: $*" 1>&2
   exit 1
}

[ -f makefile ] || die "can not find 'makefile'"

config=$1

cat > $config <<EOF
/*************************************************************/
/* Automatically generated by './mkconfig.sh': do note edit! */
/*************************************************************/
EOF

if [ ! x"`grep '^CC=gcc$' makefile`" =  x ]
then
  patchgccversion="`gcc --version|head -1|sed -e 's/,/ /g'`"
  patchgccversion="s,gcc,$patchgccversion,g"
else
  patchgccversion="s,DUMMY,DUMMY,"
fi

sed \
  -e '/^C[A-Z]*=/!d' \
  -e 's,^,#define BTOR_,' \
  -e 's,= *, ",' \
  -e 's,$,",' \
  makefile | sed -e "$patchgccversion" >> $config

curpath=`pwd`
BTOR_DEF_DATE=`date`
BTOR_DEF_VERSION=`cat VERSION`
BTOR_DEF_ID=`./getgitid.sh`

echo "#define BTOR_OS \"`uname -srmn`\"" >> $config 
echo "#define BTOR_COMPILED \"`date`\"" >> $config
echo "#define BTOR_SRC_DIR   \"$curpath/\"" >> $config
echo "#define BTOR_BIN_DIR   \"$curpath/bin/\"" >> $config
echo "#define BTOR_BUILD_DIR \"$curpath/build/\"" >> $config
echo "#define BTOR_TEST_DIR  \"$curpath/src/tests/\"" >> $config
echo "#define BTOR_LOG_DIR   \"$curpath/src/tests/log/\"" >> $config
echo "#define BTOR_CONTRIB_DIR \"$curpath/contrib/\"" >> $config
echo "#define BTOR_RELEASED \"$BTOR_DEF_DATE\"" >> $config
echo "#define BTOR_VERSION \"$BTOR_DEF_VERSION\"" >> $config
echo "#define BTOR_ID \"$BTOR_DEF_ID\"" >> $config
