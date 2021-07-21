# CMakeList.txt : CMake project for MyLibrary, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.14)

# Project name
project ("CppType")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Global vars
set (LIB_NAME_TEST MyLibraryTest)
set (LIB_NAME MyLibrary)




# Definir libreria Google Test
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/release-1.8.1.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



# Definir libreria
add_library (${LIB_NAME} STATIC
        CppType/src/int_type.cpp
        CppType/src/float_type.cpp
        CppType/src/double_type.cpp
        CppType/src/char_type.cpp
        CppType/src/string_type.cpp)

target_include_directories(${LIB_NAME}
        PRIVATE CppType/include)




# Definir libreria de pruebas
add_executable(${LIB_NAME_TEST}
        CppTypeTest/int_type_test.cpp
        CppTypeTest/float_type_test.cpp
        CppTypeTest/double_type_test.cpp
        CppTypeTest/char_type_test.cpp
        CppTypeTest/string_type_test.cpp)

target_link_libraries (${LIB_NAME_TEST}
        PRIVATE ${LIB_NAME}
        gtest_main)

target_include_directories(${LIB_NAME_TEST}
        PRIVATE CppType/include)

add_test(MyLibrary.UnitTest COMMAND ${LIB_NAME_TEST})
