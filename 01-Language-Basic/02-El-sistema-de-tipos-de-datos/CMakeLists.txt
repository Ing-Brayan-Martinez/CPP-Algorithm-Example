# CMakeList.txt : CMake project for MyLibrary, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.14)

# Project name
project ("cpp-type")

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
        Cpp-Type/src/01-int-type.cpp
        Cpp-Type/src/02-float-type.cpp
        Cpp-Type/src/03-double-type.cpp
        Cpp-Type/src/04-char-type.cpp
        Cpp-Type/src/05-string-type.cpp)

target_include_directories(${LIB_NAME}
        PRIVATE Cpp-Type/include)




# Definir libreria de pruebas
add_executable(${LIB_NAME_TEST}
        Cpp-Type-Test/01-int-type-test.cpp
        Cpp-Type-Test/02-float-type-test.cpp
        Cpp-Type-Test/03-double-type-test.cpp
        Cpp-Type-Test/04-char-type-test.cpp
        Cpp-Type-Test/05-string-type-test.cpp)

target_link_libraries (${LIB_NAME_TEST}
        PRIVATE ${LIB_NAME} )
       # gtest_main)

target_include_directories(${LIB_NAME_TEST}
        PRIVATE Cpp-Type/include)

add_test(MyLibrary.UnitTest COMMAND ${LIB_NAME_TEST})
