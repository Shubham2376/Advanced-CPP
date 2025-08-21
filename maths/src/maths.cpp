#include "maths.h"
namespace MathFunctions{
    double square(double x){
        return x*x;
    }
    double cube(double x){
        return x*x*x;
    }

    #ifdef ADVANCED_API
    double power(double base, double exponent){
        double result = 1;
        for(int i = 0; i<exponent; i++){
            result *= base;
        }
        return result;
    }
    #endif
}