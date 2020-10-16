// Friend functions

#include <iostream>
#include <cstring>

using namespace std;

class Student{

	friend double average(Student ,Student );

	private:
		char *name;
		int id;

		double grade;

	public:
		void print();
      	void setname(char const *);
      	void setgrade(double);

      	void setid(int);
      	void getname(char *);

		Student(char const * ,int, double);
		Student(Student &);

		~Student();

};

Student::Student(char const *n, int i, double g)
{
	setname(n);
	setid(i);
	setgrade(g);
}

Student::Student(Student &t)
{
    setname(t.name);
	setid(t.id);
	setgrade(t.grade);
}

Student::~Student()
{
	delete [] name;
}


void Student::print()
{
	cout << endl;
	cout << "name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "grade: " << grade << endl;
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

void Student::setgrade(double g)
{
	grade = g;
}

void Student::getname(char *n)
{
	strcpy(n,name);
}

int main()
{
	Student a("John",119, 75.5);
	a.print();

	Student b("Jessi",115,63.80);
	b.print();

	cout << "The average is " << average(a,b) << endl;

	return 0;
}

double average(Student x, Student y)
{
	return (x.grade + y.grade)/2;
}
