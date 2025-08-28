cmake_minimum_required(VERSION 4.1) 
project(physics)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
src/physics.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_library(physics SHARED ${SOURCES}) 

target_compile_definitions(physics PRIVATE PHYSICS_EXPORT)

target_include_directories(physics PUBLIC include)

# install(TARGETS physics
#     RUNTIME DESTINATION "${CMAKE_BINARY_DIR}"
#     LIBRARY DESTINATION "${CMAKE_BINARY_DIR}"
#     ARCHIVE DESTINATION "${CMAKE_BINARY_DIR}"
# )
