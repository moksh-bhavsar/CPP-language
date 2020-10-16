#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{

	double pi = 3.141592653;

	cout << "0123456789" << endl;

	cout.width(10);
	cout.setf(ios::fixed|ios::left);
	cout << pi << endl;

	cout.unsetf(ios::fixed);

	cout.width(10);
	cout.setf(ios::scientific);
	cout << pi << endl;

	cout.precision(2);
	cout << pi << endl;

	return 0;
}
