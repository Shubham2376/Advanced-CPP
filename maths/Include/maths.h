#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

namespace MathFunctions
{
    double square(double x);
    double cube(double x);

    #ifdef ADVANCED_API
    double power(double base, double exponent);
    #endif
}

#endif