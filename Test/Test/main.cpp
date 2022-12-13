#include "App.h"

#include <iostream>

int main() {
   
    App test;

    try {
        test.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}