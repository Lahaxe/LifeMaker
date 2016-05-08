project(lifemaker)
cmake_minimum_required(VERSION 2.8)

set(lifemaker_MAJOR_VERSION 0)
set(lifemaker_MINOR_VERSION 1)
set(lifemaker_PATCH_VERSION 0)
set(lifemaker_VERSION
    ${lifemaker_MAJOR_VERSION}.${lifemaker_MINOR_VERSION}.${lifemaker_PATCH_VERSION})

option(BUILD_EXAMPLES "Build the examples directory." ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}" ${CMAKE_MODULE_PATH})
include(CTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

