#include "calculator.h"
#include<stdexcept> // This header file is for invalid_argument
double Calculator::add(double a,double b){
    return a+b;
}
double Calculator::sub(double a,double b){
    return a-b;
}
double Calculator::mul(double a,double b){
    return a*b;
}
double Calculator::div(double a,double b){
    if(b == 0){
        throw std::invalid_argument("Division by zero was not allowed");
        // <stdexcept> is a standard C++ header file that contains a family of standard exception classes.
        // These are predefined exception types you can use instead of making your own classes.
        // Examples in <stdexcept> include:
        // std::invalid_argument
        // std::out_of_range
        // std::length_error
        // std::domain_error
        // std::runtime_error

    }
    return a/b;
}