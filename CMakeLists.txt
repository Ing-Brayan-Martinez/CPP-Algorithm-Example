cmake_minimum_required(VERSION 3.15)

# Project name
project (CPP_Algorithm_Example VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Global vars
set (LIB_NAME_TEST AlgorithmExampleTest)
set (LIB_NAME AlgorithmExample)



# Definir libreria Google Test
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/release-1.8.1.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



# Definir libreria
add_library (${LIB_NAME} STATIC
        AlgorithmExample/src/Ordering-BubbleSort.cpp
        AlgorithmExample/src/Ordering-SelectionSort.cpp
        AlgorithmExample/src/Ordering-QuickSort.cpp
        AlgorithmExample/src/Util-Data.cpp
        AlgorithmExample/src/Dinamic-Factorial.cpp
        AlgorithmExample/src/Structure-List.cpp
        AlgorithmExample/src/Dinamic-FizzBuzz.cpp
        AlgorithmExample/src/Dinamic-Fibonacci.cpp
        AlgorithmExample/src/Encryption-Base58.cpp AlgorithmExample/src/Encryption-Base64.cpp AlgorithmExample/src/Search-BinarySearch.cpp AlgorithmExample/src/Search-ExponentialSearch.cpp AlgorithmExample/src/Search-LinearSearch.cpp)

target_include_directories(${LIB_NAME}
        PRIVATE AlgorithmExample/include)




# Definir libreria de pruebas
add_executable(${LIB_NAME_TEST}
        AlgorithmExampleTest/Ordering-BubbleSortTest.cpp
        AlgorithmExampleTest/Ordering-QuickSortTest.cpp
        AlgorithmExampleTest/Ordering-SelectionSortTest.cpp
        AlgorithmExampleTest/Dinamic-FactorialTest.cpp
        AlgorithmExampleTest/Structure-ListTest.cpp)

target_link_libraries (${LIB_NAME_TEST}
        PRIVATE ${LIB_NAME}
        gtest_main)

target_include_directories(${LIB_NAME_TEST}
        PRIVATE AlgorithmExample/include)

add_test(MyLibrary.UnitTest COMMAND ${LIB_NAME_TEST})
