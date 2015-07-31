/* 
 * File:   main.h
 * Author: Will Shackleford  {@literal <william.shackleford@nist.gov>}
 *
 * Created on July 30, 2015, 9:55 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <jni.h>

namespace javamain {

    class Main {
    private:
        jobject jthis;

    public:
        static void staticTest(jint i);
        virtual jint getI();
        Main(jint i);
        virtual ~Main();
    };

    extern void closeJVM();
}

#endif	/* MAIN_H */

