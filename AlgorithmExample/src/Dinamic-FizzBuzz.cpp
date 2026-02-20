//
// Created by Ing Brayan Martinez on 15/12/2022.
//
module;

#include <iostream>

export module dinamic.fizzbuzz;

namespace Dinamic {

    export auto FizzBuzz(unsigned int n) -> void {
        for (unsigned int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                std::cout << "FizzBuzz" << std::endl;
            } else if (i % 3 == 0) {
                std::cout << "Fizz" << std::endl;
            } else if (i % 5 == 0) {
                std::cout << "Buzz" << std::endl;
            } else {
                std::cout << i << std::endl;
            }
        }
    }
}

