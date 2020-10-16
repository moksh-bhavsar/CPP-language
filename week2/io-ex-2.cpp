#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char str[20];
	cout << "Enter an string:";

	cin.ignore(1000,'l');

	cin >> str;    							// "hello"

	cout << "|" <<str << "|" << endl;  		// "|lo|"  ignore 'hel'

	return 0;
}
