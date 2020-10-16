// shadowing the print class in the derived class class

#include <iostream>
#include <cstring>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		char * name;

	public:
		void setname(char const *);
		void print();

		Person(); 				// default constructor
		Person(char const *);
		Person(Person &); 		// copy constructor

		~Person();

};

void Person::setname(char const *n)
{
	name = new char[strlen(n)+1];
	strcpy(name, n);
}

void Person::print()
{
	if(name)
		cout << "\tname: " << name << endl;
	else
		cout << "\tThis is an empty object !" << endl;

}

Person::Person()
{
	cout << "This is default constructor for Person class !" << endl;
	name = nullptr;
}

Person::Person(char const *n)
{
	cout << "This is Person(char const *n) constructor for Person class !" << endl;
	setname(n);
}

Person::~Person()
{
	cout << "This is the Person destructor !" << endl;
	if(name)
		delete [] name;
}

Person::Person(Person &t)
{
	cout << "This is copy constructor for Person class !" << endl;
	name = new char[strlen(t.name)+1]; // doing deep copy
	strcpy(name, t.name);
}

// -----------------------------  Derived class

class Student : public Person{
	private:
		double grade;

	public:

      	void setgrade(double);
      	void print();

      	Student();    // default constructor
		Student(char const *, double);
		Student(Student &);  // copy constructor

		~Student();
};

void Student::setgrade(double g)
{
	grade =g;
}

void Student::print()
{
	Person::print();
	if(name)
		cout << "\tgrade: " << grade << endl;
}

Student::Student()
{
	cout << "This is default constructor for Student class !" << endl;
}

Student::Student(char const *n, double g): Person(n)
{
	cout << "This is Student(char const *n, double g) constructor for Person class !" << endl;
	setgrade(g);
}

Student::Student(Student &t):Person(t.name)
{
	cout << "This is copy constructor for Person class !" << endl;
	grade = t.grade;
}

Student::~Student()
{
	// The based constructor will be called after the based constructor
	cout << "This is the Student destructor !" << endl;
}

int main()
{
	Person x("John");
	x.print();

	Student y("Sarah",79.0);
	y.print();

	Person * p = new Student("Jessi",87.8);
	p-> print();

	return 0;
}
