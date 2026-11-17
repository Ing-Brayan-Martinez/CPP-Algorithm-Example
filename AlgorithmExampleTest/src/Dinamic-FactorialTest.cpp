//
// Created by Ing Brayan Martinez on 15/12/2022.
//
#include <gtest/gtest.h>
import dinamic.factorial;

TEST(FactorialTest, BasicAssertions) {
    int num = 5;

    unsigned int result = Dinamic::Factorial(num);

    std::cout << std::endl << "-- Factorial --" << std::endl << std::endl;

    std::cout << "Factorial of " << num << " is " << result << std::endl;

    EXPECT_EQ(result, 120);
    std::cout << std::endl << "Test Passed!" << std::endl;
}
