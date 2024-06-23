cmake_minimum_required(VERSION 3.28)
project(GameOfLife1970)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")

add_subdirectory(src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/src)