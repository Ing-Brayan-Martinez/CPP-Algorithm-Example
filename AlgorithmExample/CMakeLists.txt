cmake_minimum_required(VERSION 3.15)

# Project name
project(Algorithm_Example VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define library
add_library(AlgorithmExample STATIC
        src/Ordering-BubbleSort.cpp
        src/Ordering-SelectionSort.cpp
        src/Ordering-QuickSort.cpp
        src/Util-Data.cpp
        src/Dinamic-Factorial.cpp
        src/Structure-List.cpp
        src/Dinamic-FizzBuzz.cpp
        src/Dinamic-Fibonacci.cpp
        src/Encryption-Base58.cpp
        src/Encryption-Base64.cpp
        src/Search-BinarySearch.cpp
        src/Search-ExponentialSearch.cpp
        src/Search-LinearSearch.cpp)

# Optimize compilation
target_precompile_headers(AlgorithmExample PUBLIC
        <iostream>
        <vector>
        <unordered_map>)

# Expose headers
target_include_directories(AlgorithmExample PUBLIC
        include)