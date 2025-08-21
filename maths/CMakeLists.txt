cmake_minimum_required(VERSION 4.1) 
project(maths)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
src/maths.cpp
)

#include_directories(Include)

option(ADVANCED_API_ENABLE "THIS IS FOR ADVANCED API" ON) #define the variable, message, Option (if we keep option = ON then those api which are inside the flag was bydefault define people can use it)


add_library(maths STATIC ${SOURCES}) #this contain name of library, what kind of library and then what are the sources that will make this static library 

if(ADVANCED_API_ENABLE) #if ADVANCED_API_ENABLE was define then we go inside this if statement
    message("inside the if block")
    target_compile_definitions(maths PUBLIC ADVANCED_API) # if we use PRIVATE then ADVANCED_API defination is only accessible to maths target or inside the maths folder here we use public so it is accessible to other target as well which was linking to maths library
endif()


target_include_directories(maths PUBLIC include) #include is a directory which we try to include and maths is a target directory 