// Static members for the student class

#include <iostream>
#include <cstring>

using namespace std;

class Student{

	private:
		char *name;
		int id;

	public:

		static int num_student_obj;


		void print();
      	void setname(char const *);

				void setid(int);
      	void getname(char *);

		Student(char const * ,int);
		Student(Student &);  // copy constructor

		~Student();

		static void help();

};

int Student::num_student_obj = 0;  // Initialization

Student::Student(char const *n, int i)
{
	setname(n);
	setid(i);
	num_student_obj++;
}

Student::Student(Student &t)
{
    setname(t.name);
	setid(t.id);
	num_student_obj++;

}

Student::~Student()
{
	delete [] name;
    num_student_obj--;  // initialized to 0
}


void Student::print()
{
	cout << endl;
	cout << "name: " << name << endl;
	cout << "ID: " << id << endl;
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

void Student::help()
{
	cout << "This is a class for holding a student's information."  << endl;
}

int main()
{

	Student::help();

	Student a("John",119);
	a.print();

	cout << "Number of student objects : " << Student::num_student_obj << endl;

	Student b("Jessi",115);
	b.print();

	cout << "Number of student objects : " << Student::num_student_obj << endl;


	return 0;
}
