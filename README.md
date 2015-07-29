# CppCallJavaExample
Example C++ application calling a Java function.

This is a more complete example of what was started here:

http://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/invocation.html

To compile and run:  

export JAVA_HOME=???   
make test

If it succeeds you should see:  

g++ -c -fPIC -I /usr/local/jdk1.8.0_25/include/linux -I /usr/local/jdk1.8.0_25/include/ cppcalljava.cxx -o cppcalljava.o  

g++ cppcalljava.o -fPIC -I /usr/local/jdk1.8.0_25/include/linux -I /usr/local/jdk1.8.0_25/include/ -L /usr/local/jdk1.8.0_25/jre/lib/i386/server -ljvm -o cppcalljava  

/usr/local/jdk1.8.0_25/bin/javac Main.java  

env LD_LIBRARY_PATH=/home/shackle/rcslib//lib/:/usr/local/jdk1.8.0_25/jre/lib/i386/client/::.:/usr/local/lib:/local/lib/:/usr/local/jdk1.8.0_25/jre/lib/i386/server ./cppcalljava  

Main.test(100) called.

Tested on linux(Ubuntu 14.4)  with JAVA_HOME=/usr/local/jdk1.8.0_25, the Makefile will likely need to be edited 
to match the directory layout for your version of the jdk. 

On x64 systems use:  

make JRE_TYPE=amd64/server  

