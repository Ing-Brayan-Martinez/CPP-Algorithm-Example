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
        AlgorithmExample/src/dinamica/HelloWord.cpp
        AlgorithmExample/src/dinamica/ChartType.cpp AlgorithmExample/src/ordenamiento/BubbleSort.cpp AlgorithmExample/src/ordenamiento/SelectionSort.cpp AlgorithmExample/src/ordenamiento/QuickSort.cpp AlgorithmExample/src/utils/Util.cpp AlgorithmExample/include/Util.h AlgorithmExample/include/SelectionSort.h AlgorithmExample/include/QuickSort.h AlgorithmExample/include/BubbleSort.h)

target_include_directories(${LIB_NAME}
        PRIVATE AlgorithmExample/include)




# Definir libreria de pruebas
add_executable(${LIB_NAME_TEST}
        AlgorithmExampleTest/dinamica/CharTypeTest.cpp AlgorithmExampleTest/dinamica/HelloWordTest.cpp AlgorithmExampleTest/ordenamiento/BubbleSortTest.cpp AlgorithmExampleTest/ordenamiento/QuickSortTest.cpp AlgorithmExampleTest/ordenamiento/SelectionSortTest.cpp)

target_link_libraries (${LIB_NAME_TEST}
        PRIVATE ${LIB_NAME}
        gtest_main)

target_include_directories(${LIB_NAME_TEST}
        PRIVATE AlgorithmExample/include)

add_test(MyLibrary.UnitTest COMMAND ${LIB_NAME_TEST})
