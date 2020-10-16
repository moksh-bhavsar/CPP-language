#include <iostream>
#include <cstring>

using namespace std;

void readnames(char * [], int );
void writenames(char * [], int );
void freenames(char * [], int );


int main()
{
	char *list[100];

	int n;
	cout << "Enter the number of student: ";
	cin >> n;

	readnames(list,n);
	writenames(list,n);
	freenames(list,n);

	return 0;
}

void readnames(char *list [], int n)
{
	for (int i = 0; i < n; ++i)
	{
		char x[200];

		cout << "Enter a name: ";
		cin >> x;

		list[i] = new char[strlen(x)+1];		// creating a new array of char inside a char and includeing '+ 1' for "\0"
		strcpy(list[i],x);

	}
}
void writenames(char *list [], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << list[i] << endl;
	}
}
void freenames(char *list [], int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete [] list[i];;
	}
}
