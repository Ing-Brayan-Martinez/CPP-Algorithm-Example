//
// Created by Ing Brayan Martinez on 15/12/2022.
//
#include <gtest/gtest.h>
import dinamic.fibonacci;

TEST(FibonacciTest, BasicAssertions) {
    int num = 20;

    unsigned int result = Dinamic::Fibonacci(num);

    std::cout << std::endl << "-- Fibonacci --" << std::endl << std::endl;

    std::cout << "Fibonacci of " << num << " is " << result << std::endl;

    EXPECT_EQ(result, 6765);
    std::cout << std::endl << "Test Passed!" << std::endl;
}
