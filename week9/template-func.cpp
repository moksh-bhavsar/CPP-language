#include <iostream>

using namespace std;

template <class T>
void swapvalues(T &var1, T &var2)
{
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

template <class T>
T minValue(T x[], int n)
{
	T min = x[0];
	for(int i= 1; i < n; i++)
		if(min > x[i])
			min = x[i];
	return min;

}

int main()
 {
 	double x = 1.5, y = 2.3;
 	
 	cout << "x = " << x << ", y = " << y <<endl;
 	swapvalues(x, y);
 	cout << "x = " << x << ", y = " << y <<endl;

 	double a[] = {4, 2, 5, 1};
 	cout << "Min value = " << minValue(a, 4) << endl;

 	return 0;
 } 

