
#include "mex-lib.h"
#include <iostream>

int add(int a, int b) {
    return a + b;
}

void print_msg(const char* msg) {
    std::cout << "[MYLIB] " << msg << std::endl;
}
