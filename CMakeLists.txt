# versiones minimas del compilador
# https://stackoverflow.com/questions/78498268/getting-started-with-cmake-3-28-and-c20-modules
# https://cmake.org/cmake/help/latest/manual/cmake-cxxmodules.7.html

# instalar gcc 14
# https://www-baeldung-com.translate.goog/linux/gnu-compiler-collection-ubuntu-installation?_x_tr_sl=en&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=sge
# https://www.cherryservers.com/blog/how-to-install-gcc-on-ubuntu

# ejemplos de como compilar c++ 20 con cmake
# https://gitlab.kitware.com/cmake/cmake/-/issues/25731
# https://www.kitware.com/import-cmake-the-experiment-is-over/

cmake_minimum_required(VERSION 3.28)

# Project name
project(CPP_Algorithm_Example LANGUAGES CXX)

# Force CMake to attempt scanning even if the compiler is being quiet about it
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library
add_subdirectory(AlgorithmExample)

# Define executable
add_subdirectory(AlgorithmExampleExec)




## Enable testing from execution in the CLI
#enable_testing()
#
## Define library Google Test (latest stable version)
#include(FetchContent)
#FetchContent_Declare(
#    googletest
#    GIT_REPOSITORY https://github.com/google/googletest.git
#    GIT_TAG        v1.16.0
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

# Define unit tests executable
#add_subdirectory(AlgorithmExampleTest)
