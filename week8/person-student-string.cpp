// Overriding the print class in the derived class class

#include <iostream>
#include <string>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		virtual void print();

		Person(); 				// default constructor
		Person(const char *);
		Person(Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();
};

void Person::setname(char const *n)
{
	name = n;
}

void Person::print()
{
	cout << "The person information is:" << endl;
	if(name != "")
		cout << "\tname: " << name << endl;
	else
		cout << "\tThis is an empty object !" << endl;

}

Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(Person &t):name(t.name)
{
}

// -----------------------------  Student class

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
    cout << "The student information is:" << endl;
	if(name != ""){
		cout << "\tname:" << name << endl;
		cout << "\tgrade: " << grade << endl;
	}
}

Student::Student(): grade(0)
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

Student::~Student()
{
}

int main()
{  
	Person x("John");
	x.print();

	Student y("Sarah",79.0);  
	y.print();

	Person * p = new Person("Alex");
	p-> print();

	delete p;

	p = new Student("Jessi",87.8);
	p-> print();

	p->setname("Kourosh");

	delete p;

	return 0; 
}



