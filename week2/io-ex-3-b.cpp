#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{

	double pi = 3.141592653;

	cout << setw(10) << setprecision(3) << pi << endl; // using manipulators
	cout << pi << endl;

	int x = 127;

	cout << hex << x <<  endl;

	cout << oct << x <<  endl;

	return 0;
}
