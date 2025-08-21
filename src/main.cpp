#include<iostream>
#include "calculator.h"
#include "maths.h"

using namespace std;
int main(){
     Calculator calc;
    double x, y;
    char choice;

    cout << "Enter First number: ";
    cin >> x;
    cout << "\nChoose operation:\n";
    cout << "+. Addition\n";
    cout << "-. Subtraction\n";
    cout << "*. Multiplication\n";
    cout << "/. Division\n";
    cout << "Enter choice : ";
    cin >> choice;
    cout << "Enter Second number: ";
    cin >> y;

    try {
        switch (choice) {
            case '+':
                cout << "Result: " << calc.add(x, y) << endl;
                break;
            case '-':
                cout << "Result: " << calc.sub(x, y) << endl;
                break;
            case '*':
                cout << "Result: " << calc.mul(x, y) << endl;
                break;
            case '/':
                cout << "Result: " << calc.div(x, y) << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;   // handle division by zero 
        // e is the exception object you caught.
        // what() is a member function of the base class std::exception.
        // It returns a C-style string (const char*) containing a description of the exception.
    }
    cout << "cube: " << MathFunctions::cube(3) << endl;

    #ifdef ADVANCED_API
    cout << "Power: " << MathFunctions::power(2,3) << endl;
    #endif
    
    return 0;
}