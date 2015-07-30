#!/bin/sh

if test "x${JAVA_HOME}" != "x" ; then
    echo "${JAVA_HOME}";
else 
    locate bin/javac | sed 's#bin/javac##' | head -1
fi