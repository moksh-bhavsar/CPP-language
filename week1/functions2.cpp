// call by reference

#include <iostream>

using namespace std;

void swap(int & ,int &); // function prototype


int main()
{
	int x = 1 , y =2 ;

	cout << "before: " << x << " " << y << endl;

	swap(x,y);

	cout << "after: " << x << " " << y << endl;

	return 0;
}

// function definitions

void swap(int &x,int &y)
{
	int temp = x;
	x = y;
	y = temp;
} 
