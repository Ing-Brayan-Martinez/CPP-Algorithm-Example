
namespace Dinamic {

    auto Fibonacci(unsigned int n) -> unsigned int {
        /* If the input is 0 or 1 just return the same
           This will set the first 2 values of the sequence */
        if (n <= 1) {
            return n;
        }

        /* Add the last 2 values of the sequence to get next */
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}