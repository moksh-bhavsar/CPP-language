#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char str[20];
	cout << "Enter an string:";

	cin.ignore();

	cin >> str;    							// "hello"

	cout << "|" <<str << "|" << endl;  		// "|ello|"

	return 0;
}
