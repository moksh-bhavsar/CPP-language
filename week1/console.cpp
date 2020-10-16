// using cerr

#include <iostream>

using namespace std;

int main()
{
	int x, y;

	cout << "Enter the first number: ";
	cin >> x;
	cout << "Enter the second number: ";
	cin >> y;

	if (x < 0 || y < 0)
		cerr << "Error! The number is negative." << endl;
	else if (x > y)
		cout << "The maximum is : " << x << endl;
	else
		cout << "The maximum is : " << y << endl;

	return 0;
}
