//
// Created by Ing Brayan Martinez on 15/12/2022.
//

namespace Dinamic {

    auto Factorial(unsigned int n) -> unsigned int {
        if (n == 0)
            return 1;
        return n * Factorial(n - 1);
    }
}