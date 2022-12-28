//
// Created by Qard Group CA on 12/15/22.
//
#include <gtest/gtest.h>
#include <Dinamic-FizzBuzz.h>

TEST(FizzBuzzTest, BasicAssertions) {
    int num = 20;

    std::cout << std::endl << "-- FizzBuzz --" << std::endl << std::endl;

    Dinamic::FizzBuzz(num);

    std::cout << std::endl << "Test Passed!" << std::endl;
}