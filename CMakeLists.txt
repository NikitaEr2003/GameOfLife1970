cmake_minimum_required(VERSION 3.28)
project(GameOfLife1970)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

add_subdirectory(src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/src)
