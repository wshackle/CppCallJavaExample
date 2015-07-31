/* 
 * File:   main.cpp
 * Author: Will Shackleford  {@literal <william.shackleford@nist.gov>}
 *
 * Created on July 30, 2015, 2:25 PM
 */

#include <cstdlib>
#include <javamain.h>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
using namespace javamain;

/*
 * 
 */
int main(int argc, char** argv) {
    Main::staticTest(200);
    Main::staticTest(300);
    const jint origI = (jint) 400;
    Main *m = new Main(origI);
    jint i = m->getI();
    std::cerr << "cpp m->getI() returned: " << i << std::endl;
    delete m;
    closeJVM();
    if(i!= origI) {
        cerr << i<<"!=" <<origI << endl;
        exit(1);
    }
    return 0;
}

