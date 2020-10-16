#include <iostream>

using namespace std;

double volume(int, int = 1,int = 1); // function prototype with default parameters

int main()
{
	cout << volume(2) << endl;	// function call
	cout << volume(2,3) << endl;
	cout << volume(2,3,4) << endl;

	return 0;
}

// function definitions

double volume(int x, int y, int z)
{
	return x * y * z;
}
