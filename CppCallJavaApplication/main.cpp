/* 
 * File:   main.cpp
 * Author: Will Shackleford  {@literal <william.shackleford@nist.gov>}
 *
 * Created on July 30, 2015, 2:25 PM
 */

#include <cstdlib>
#include <javamain.h>
#include <vector>
using namespace std;
using namespace javamain;

/*
 * 
 */
int main(int argc, char** argv) {
    test(200);
    test(300);
    closeJVM();
    return 0;
}

