// function overloading means two functions have same name but different number of arguments and/or different types of arguments.

// Function overloading is used because of the natural concept of having things which work similar to have same name

#include <iostream>

using namespace std;

void print_area(double);			// function prototype
void print_area(double,double);

int main()
{
	print_area(3.0);
	print_area(2.0,3.0);

	return 0;
}

// function definitions

void print_area(double x)
{
	cout << "The circle area is " << x * x * 3.14 << endl;
}

void print_area(double x, double y)
{
	cout << "The square area is " << x * y << endl;
}
