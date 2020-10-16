#include <iostream>
#include <cstring>

using namespace std;

void reverse(char s[]); // prototype

int main() // function definition
{
	char a[100];

	cout << "Enter a string: ";
	cin >> a;

	reverse(a);

	cout << a << endl;

	return 0;
}
void reverse(char s[])
{
	for (int i = 0, j = strlen(s)-1; i < j ; i++, j--)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
