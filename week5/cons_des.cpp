// When constructor and destructor are called?

#include <iostream>
#include <cstring>

using namespace std;

class Test{
	private:
		int id;

	public:
		Test(int);
		Test(Test &); // copy constructor always uses call-by-reference. copy constructor is the constructor which gets the same class as the type of the arguments.

		~Test();
};

Test::Test(int i )
{
	id = i;
	cout << " Creating object " << id << endl;
}

Test::Test(Test &t)
{
	id = t.id;
	cout << " Creating object (copy) " << id << endl;
}
Test::~Test()
{
	cout << " Destructing object " << id << endl;

}

void f(Test);

Test a(1);

int main()
{
	Test b(2);

	f(b);

	return 0;
}

void f(Test t)
{
	Test c(3);
}
