
OBJEXT=.o
EXEEXT=
CLASSEXT=.class

JDK_DIR=${JAVA_HOME}
JAVAC=${JDK_DIR}/bin/javac
PLAT=linux
JRE_TYPE=i386/server
CXXFLAGS+= -fPIC -I ${JDK_DIR}/include/${PLAT} -I ${JDK_DIR}/include/
JNI_LIB_DIR= ${JDK_DIR}/jre/lib/${JRE_TYPE}
LDFLAGS+=  -L ${JNI_LIB_DIR} -ljvm

all : test
.PHONY: all test clean

clean:
	-\rm Main${CLASSEXT} cppcalljava${EXEEXT} cppcalljava${OBJEXT}

test : cppcalljava${EXEEXT} Main${CLASSEXT}
	env LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${JNI_LIB_DIR} ./cppcalljava${EXEEXT}

Main.class : Main.java
	${JAVAC} $^

cppcalljava${OBJEXT} : cppcalljava.cxx
	$(CXX) -c ${CXXFLAGS} $^ -o $@

cppcalljava${EXEEXT} : cppcalljava${OBJEXT}
	$(CXX) $^ ${CXXFLAGS} ${LDFLAGS} -o $@


