#include <mex-lib.h>
#include <iostream>

int example_color ( ) {
    std::cout << Colors::brown  << "===|" << Colors::green  << "  Created by Dmitry Denkin (c) 2026  " << Colors::brown << "|======" << std::endl;
    std::cout << Colors::blue    << " *******          " << Colors::cyan << " S y s t e m   I n f o r m a t i o n " << Colors::blue   << "******" << Colors::reset << std::endl;
    
    return 0;
}
