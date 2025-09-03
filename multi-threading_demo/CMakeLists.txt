cmake_minimum_required(VERSION 4.1)
project(simplecalculator)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
#main.cpp
main2.cpp
threading.cpp
)

add_executable(multi-threading_demo ${SOURCES})