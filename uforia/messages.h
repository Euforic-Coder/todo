#ifndef MESSAGES_H
#define MESSAGES_H

#include <iostream>
#include <stdlib.h>

namespace uforia {

    // Prints a bulletin with a dot or a cross depending on if the bool is true or false
    void bulletin(std::string s, bool assert = true) {
        if (assert) {
            std::cout << "\033[32m • " << s << "\033[m" << std::endl;
        } else {
            std::cout << "\033[31m × " << s << "\033[m" << std::endl;
        }
    }

    // Prints an error message and exits the program depending on if the bool is true
    void error(std::string s, bool exit = true) {
        std::cout << "\033[31m" << s << "\033[m" << std::endl;
        if (exit) {
            std::exit(0);
        }
    }
}
#endif // MESSAGES_H