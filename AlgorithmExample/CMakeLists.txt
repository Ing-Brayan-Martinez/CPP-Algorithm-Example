cmake_minimum_required(VERSION 3.20)

# Project name
project(Algorithm_Example VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library
add_library(AlgorithmExample STATIC)

# Add C++ modules (CMake 3.20 experimental support)
# Note: FILE_SET CXX_MODULES requires CMake 3.28+, so we add modules as regular sources
# Separate modules by dependency level to ensure correct compilation order
set(BASE_MODULES
    src/Util-Object.cppm
)

set(DEPENDENT_MODULES
    src/Structure-List.cppm    # Depends on Util-Object
)

set(INDEPENDENT_MODULES
    src/Dinamic-FizzBuzz.cppm
    src/Dinamic-Factorial.cppm
    src/Dinamic-Fibonacci.cppm
    src/Ordering-BubbleSort.cppm
    src/Ordering-SelectionSort.cppm
    src/Ordering-QuickSort.cppm
    src/Util-Data.cppm
)

set(LEAF_MODULES
    src/Structure-ArrayList.cppm  # Depends on Structure-List
    src/Structure-LinkedList.cppm   # Depends on Structure-List
)

# Add base modules first (no dependencies)
target_sources(AlgorithmExample PUBLIC ${BASE_MODULES})

# Add independent modules (no dependencies on our modules)
target_sources(AlgorithmExample PUBLIC ${INDEPENDENT_MODULES})

# Add dependent modules (depend on base modules)
target_sources(AlgorithmExample PUBLIC ${DEPENDENT_MODULES})

# Add leaf modules (depend on dependent modules)
target_sources(AlgorithmExample PUBLIC ${LEAF_MODULES})

# Configure each .cppm file to be compiled as a C++ module
foreach(MODULE_FILE ${BASE_MODULES} ${DEPENDENT_MODULES} ${INDEPENDENT_MODULES} ${LEAF_MODULES})
    set_source_files_properties(${MODULE_FILE} PROPERTIES
        LANGUAGE CXX
    )
endforeach()

# Add module-specific flags for Apple Clang
# Apple Clang requires -fmodules and -fcxx-modules for C++20 modules
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND APPLE)
    foreach(MODULE_FILE ${BASE_MODULES} ${DEPENDENT_MODULES} ${INDEPENDENT_MODULES} ${LEAF_MODULES})
        set_source_files_properties(${MODULE_FILE} PROPERTIES
            COMPILE_OPTIONS "-fmodules;-fcxx-modules"
        )
    endforeach()
    
    # Get the object file directory where .pcm files are generated
    get_filename_component(OBJ_DIR "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/AlgorithmExample.dir" ABSOLUTE)
    
    # Force compilation order using OBJECT_DEPENDS
    # Structure-List must wait for Util-Object to compile and generate its .pcm file
    # We use the object file path to ensure Util-Object.cppm compiles first
    set(UTIL_OBJECT_O "${OBJ_DIR}/src/Util-Object.cppm.o")
    set(STRUCTURE_LIST_O "${OBJ_DIR}/src/Structure-List.cppm.o")
    
    set_source_files_properties(
        src/Structure-List.cppm
        PROPERTIES
            OBJECT_DEPENDS "${UTIL_OBJECT_O}"
    )
    
    # Structure-ArrayList and Structure-LinkedList must wait for Structure-List
    set_source_files_properties(
        src/Structure-ArrayList.cppm
        src/Structure-LinkedList.cppm
        PROPERTIES
            OBJECT_DEPENDS "${STRUCTURE_LIST_O}"
    )
    
    # Add module search paths - Clang needs to find .pcm files (Precompiled Module files)
    # Clang generates these in the same directory as .o files
    target_compile_options(AlgorithmExample PRIVATE
        -fprebuilt-module-path=${OBJ_DIR}
    )
    
    # For Apple Clang, we may also need to specify the module output directory
    # This ensures modules can find each other's interface files
    target_compile_options(AlgorithmExample PRIVATE
        -Xclang -fmodule-map-file-home-is-cwd
    )
    
    # Note: In CMake 3.20, module dependencies are not fully supported
    # We rely on OBJECT_DEPENDS and the order in target_sources to ensure
    # correct compilation order. If parallel compilation causes issues,
    # compile with -j1 for the first build: cmake --build . -j1
endif()