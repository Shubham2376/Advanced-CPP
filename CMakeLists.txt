cmake_minimum_required(VERSION 4.1) # anyone which use this code should atleast have this version of cmake install in our system
project(simplecalculator) #we have to give the project name 

set(CMAKE_CXX_STANDARD 17) #Atleast c++17 should be required to compile the project
set(CMAKE_CXX_STANDARD_REQUIRED True) #what this line do that until and unless you have c++ 17 or higher version this line throw error it won't able to go ahead after this

#we have to generate executable out of my project for that we have to write this 
#add_executable(simplecalculator src/main.cpp Calculator/src/calculator.cpp) #here simplecalculator is a name of a executable and src/main.cpp Calculator/src/calculator.cpp this are those file from which executable file was formed
set(SOURCES
src/main.cpp
Calculator/src/calculator.cpp
)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

include(FetchContent)

#declare the spdlog dependency
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0
)
# we can do the above thing with this also
# ExternalProject_Add(
#     my_dependency
#     GIT_REPOSITORY https://github.com/some/repo.git
#     GIT_TAG some_tag
#     CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_PREFIX>
# )

#make spdlog available
FetchContent_MakeAvailable(spdlog)

add_subdirectory(maths) #what this piece of code do that it will try to go inside the maths folder and check CMakeLists.txt file and whatever present inside the CMakeLists.txt file it try to execute that 

add_subdirectory(physics)

include_directories(Calculator/Include)

add_executable(simplecalculator ${SOURCES}) #we access the variable that we define using the ${} 

# This is how we add spdlog library to our project
# Link the spdlog library to the executable

target_link_libraries(simplecalculator maths physics spdlog::spdlog) #it take first argument executable which we targeting for and second argument the static lib which we targting for 

#ensure include directories are set up correctly
target_include_directories(simplecalculator PRIVATE ${spdlog_SOURCE_DIR}/include)