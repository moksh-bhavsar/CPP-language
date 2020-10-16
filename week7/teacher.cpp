// Constructor/Destructor in derived class

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

class Teacher: public Person{
	private:
		double salary;
		
	public:
		
		void setSalary(double);
		void printTeacher();
		
		Teacher();	// Default constructor
		Teacher(char const *, double);
		Teacher(Teacher  &); // Copy constructor
	
		~Teacher();
};

void Teacher::setSalary(double n){
	salary = n;
}

void Teacher::printTeacher(){
	print();
	if (name)
		cout << "\tSalary: " << salary << endl;
}

Teacher::Teacher(){
	cout << "This is default constructor for Teacher class" << endl;
}

Teacher::Teacher(char const *c, double n): Person(c){
	salary = n;
	cout << "This is Teacher(char const *c, double n) constructor for the Person class" << endl; 
}

Teacher::Teacher(Teacher &t): Person(t.name){
	cout << "This is copy constructor for Person class" << endl;
	setSalary(t.salary);
}

Teacher::~Teacher(){
	cout << "This is Teacher Destroyer!" << endl;
}
int main()
{  
	//Teacher x;
	//x.printTeacher();

	Teacher y("Sarah",79.0);  
	y.printTeacher();

	return 0; 
}
