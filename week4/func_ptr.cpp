// This program shows how to pass another function to a function!
#include <iostream>

using namespace std;

int sqrt(int);
int neg(int);

void runf(int (*p)(int), int x);

int main()
{
	runf(sqrt,6);
	runf(neg,7);

	return 0;
}

int sqrt(int x)
{
	return x*x;
}

int neg(int x)
{
	return -x;
}
void runf(int (*p)(int), int x)
{
	cout << "The function returns :" << p(x) << endl;
}
