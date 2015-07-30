#!/bin/sh

if test "x${JAVA_HOME}" != "x" ; then
    export JDK_DIR="${JAVA_HOME}";
elif test "x${JDK_DIR}" = "x" ; then
    export JDK_DIR=`./findJavaHome.sh`;
fi

find ${JDK_DIR} -name libjvm.so | sed 's#libjvm.so##' | head -1
