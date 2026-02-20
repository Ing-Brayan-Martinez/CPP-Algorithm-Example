cmake_minimum_required(VERSION 3.28)

# Project name
project(Algorithm-Example LANGUAGES CXX)

# Force CMake to attempt scanning even if the compiler is being quiet about it
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library
add_library(AlgorithmExample STATIC)

# This tells CMake these files are C++ Modules
target_sources(AlgorithmExample
        PUBLIC
        FILE_SET CXX_MODULES FILES
        src/Util-Object.cpp
        src/Structure-List.cpp
        src/Dinamic-FizzBuzz.cpp
        src/Dinamic-Factorial.cpp
        src/Dinamic-Fibonacci.cpp
        src/Ordering-BubbleSort.cpp
        src/Ordering-SelectionSort.cpp
        src/Ordering-QuickSort.cpp
        src/Util-Data.cpp
        src/Structure-ArrayList.cpp  # Depends on Structure-List
        src/Structure-LinkedList.cpp # Depends on Structure-List
)

set_property(TARGET AlgorithmExample
        PROPERTY IMPORTED_CXX_MODULES_COMPILE_FEATURES cxx_std_20)

