// This program shows how you can catch and handle an exception occurring inside another function

#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

class DivideByZero
{};

double safeDivide(int top, int bottom) throw (DivideByZero); // prototype

int main( )
{
    int numerator;
    int denominator;
    double quotient;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    try
    {
        quotient = safeDivide(numerator, denominator);
    }
    catch(DivideByZero)
    {
        cout << "Error: Division by zero!" << endl;
        cout << "Program aborting." << endl;
        exit(1);

    }
    cout << numerator << "/" << denominator << " = " << quotient << endl;
    cout << "End of program.\n";

    return 0;
}

double safeDivide(int top, int bottom) throw (DivideByZero)
{
    if (bottom == 0)
        throw DivideByZero();
    return top / static_cast<double>(bottom);

}