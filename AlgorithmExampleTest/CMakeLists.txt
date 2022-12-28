cmake_minimum_required(VERSION 3.15)

# Project name
project(AlgorithmExampleTest VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define executable
add_executable(AlgorithmExampleTest
        src/Ordering-BubbleSortTest.cpp
        src/Ordering-QuickSortTest.cpp
        src/Ordering-SelectionSortTest.cpp
        src/Dinamic-FactorialTest.cpp
        src/Structure-ListTest.cpp
        src/Dinamic-FibonacciTest.cpp
        src/Dinamic-FizzBuzzTest.cpp)

# Link libraries
target_link_libraries(AlgorithmExampleTest PRIVATE
        AlgorithmExample
        gtest_main)

add_test(NAME AlgorithmExample.UnitTest COMMAND AlgorithmExampleTest)