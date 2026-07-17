
#include <iostream>
#include "colors.h"

int example_color() {
    std::cout << Colors::brown  << "===|" 
              << Colors::green  << "  Created by Dmitry Denkin (c) 2026  " 
              << Colors::brown  << "|===" 
              << Colors::reset 
              << std::endl;
    return 0;
}