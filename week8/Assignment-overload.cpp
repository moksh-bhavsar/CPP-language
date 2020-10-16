// Overriding the print class in the derived class class

#include <iostream>
#include <cstring>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		char * name;
	    
	public:
		void setname(char const *);
		virtual void print();

		Person(); 				
		Person(char const *);
		Person(Person &); 		

		Person & operator=(const Person &);

		virtual ~Person();
};

Person & Person::operator=(const Person & s)
{
	if(name)
		delete [] name;
	setname(s.name);
	return *this;
}

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
	name = nullptr;
}

Person::Person(char const *n)
{
	setname(n);
}

Person::~Person()
{
	cout << "Person Destructor for " << name << "!" << endl;
	if(name)
		delete [] name;
}

Person::Person(Person &t)
{
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

		Student & operator=(const Student &);

};

Student & Student::operator=(const Student & s)
{
	Person::operator=(s);
	grade = s.grade;

	return *this;
}


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
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(Student &t):Person(t.name)
{
	grade = t.grade;
}

int main()
{  
	Person x("John");
	Person y("Sarah");
	
	Person z = x;   // calling copy constructor of Person
	z.print();

	y = x;			// calling operator= of Person
	y.print();

	Student a("Jessi", 67.89);
	a.print();

	Student b;

	b = a;

	b.print();


	return 0; 
}



