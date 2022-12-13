#include "WindowCreator.h"

#include <iostream>

int main() {
   
    WindowCreator test;

    try {
        test.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}