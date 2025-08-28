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

add_subdirectory(maths) #what this piece of code do that it will try to go inside the maths folder and check CMakeLists.txt file and whatever present inside the CMakeLists.txt file it try to execute that 

add_subdirectory(physics)

include_directories(Calculator/Include)

add_executable(simplecalculator ${SOURCES}) #we access the variable that we define using the ${} 

target_link_libraries(simplecalculator maths physics) #it take first argument executable which we targeting for and second argument the static lib which we targting for 