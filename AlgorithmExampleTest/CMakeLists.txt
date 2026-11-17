cmake_minimum_required(VERSION 3.28)

# Project name
project(AlgorithmExampleTest LANGUAGES CXX)

# Force CMake to attempt scanning even if the compiler is being quiet about it
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define executable
add_executable(AlgorithmExampleTest
        src/Dinamic-FactorialTest.cpp
        src/Dinamic-FibonacciTest.cpp
        src/Dinamic-FizzBuzzTest.cpp
        src/Ordering-BubbleSortTest.cpp
        src/Ordering-QuickSortTest.cpp
        src/Ordering-SelectionSortTest.cpp
        src/Structure-ListTest.cpp
)

# Link libraries
target_link_libraries(AlgorithmExampleTest PRIVATE
        AlgorithmExample
        gtest_main)

# Execute from CLI
add_test(NAME ExecuteAllCTest
        COMMAND AlgorithmExampleTest)
