// Using constructor and Destructor for Student class

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

      	Student(); //default constructor
		Student(char const * n,int);

		~Student();
};

Student::Student()
{
	cout << "Default Constructor!" << endl;
}

Student::Student(char const *n, int i )
{
	setname(n);
	setid(i);
}

Student::~Student()
{
	delete [] name;
}


void Student::print()
{
	cout << "name: " << name << endl;
	cout << "ID: " << id << endl;
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
	Student john;

	john.setname("John");
	john.setid(115);

	john.print();

	char s[100];
	john.getname(s);
	cout << s << endl;

	Student jessi("Jessi",119);
	jessi.print(); 
	
	return 0; 
}


