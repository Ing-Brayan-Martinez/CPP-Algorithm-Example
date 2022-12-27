//
// Created by Qard Group CA on 12/15/22.
//
#include <gtest/gtest.h>
#include <Dinamic-Factorial.h>

TEST(FactorialTest, BasicAssertions) {
    int num = 5;

    unsigned int result = Dinamic::Factorial(num);

    std::cout << std::endl << "-- Factorial --" << std::endl << std::endl;

    std::cout << "Factorial of " << num << " is " << result << std::endl;

    EXPECT_EQ(result, 120);
    std::cout << std::endl << "Test Passed!" << std::endl;
}