// Copy constructor for the student class

#include <iostream>
#include <cstring>

using namespace std;

class Student{

	private:
		char *name;
		int id;

	public:
		void print();
    void setname(char const *);
    void setid(int);
    void getname(char *);

		Student(char const * ,int);
		Student(Student &);  // copy constructor

		~Student();

};

Student::Student(char const *n, int i )
{
	setname(n);
	setid(i);
}

Student::Student(Student &t)
{
	cout << "The copy constructor is called !" << endl;
	name = new char[strlen(t.name)+1];
	strcpy(name, t.name);
	id = t.id;
}

Student::~Student()
{
	delete [] name;
}


void Student::print()
{
	cout << endl;
	cout << "name: " << name << endl;
	cout << "ID: " << &id << endl;
	cout << endl;

}

void Student::setname(char const *n)
{
	name = new char[strlen(n)+1];
	strcpy(name, n);
}

void Student::setid(int i)
{
	id = i;
}

void Student::getname(char *n)
{
	strcpy(n,name);
}

int main()
{
	Student a("John",119);
	a.print();

	Student b = a; // copy constructor will be called
	b.print();


	return 0;
}
