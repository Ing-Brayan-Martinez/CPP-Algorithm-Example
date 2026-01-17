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
add_library(AlgorithmExample INTERFACE IMPORTED)

# This tells CMake these files are C++ Modules
target_sources(AlgorithmExample
        INTERFACE
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
            src/Structure-ArrayList.cppm  # Depends on Structure-List
            src/Structure-LinkedList.cppm # Depends on Structure-List
)

set_property(TARGET AlgorithmExample
        PROPERTY IMPORTED_CXX_MODULES_COMPILE_FEATURES cxx_std_20)

