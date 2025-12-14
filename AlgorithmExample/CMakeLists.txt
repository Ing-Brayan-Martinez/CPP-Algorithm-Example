cmake_minimum_required(VERSION 3.28)

# Project name
project(Algorithm_Example VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library
add_library(AlgorithmExample STATIC)

# Add C++ modules using FILE_SET CXX_MODULES
target_sources(AlgorithmExample
    PUBLIC
    FILE_SET CXX_MODULES FILES
        src/Util-Object.cppm
        src/Structure-List.cppm
        src/Dinamic-FizzBuzz.cppm
        src/Dinamic-Factorial.cppm
        src/Dinamic-Fibonacci.cppm
        src/Ordering-BubbleSort.cppm
        src/Ordering-SelectionSort.cppm
        src/Ordering-QuickSort.cppm
        src/Util-Data.cppm
        src/Structure-ArrayList.cppm
        src/Structure-LinkedList.cppm
)