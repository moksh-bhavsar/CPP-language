// Copy constructor for the student class

#include <iostream>
#include <cstring>

using namespace std;

class Student{

	private:
		char *name;
		int id;

		double grade;

	public:
		void print();
      	void setname(char const *);

      	void setid(int);
      	void getname(char *);
      	void setgrade(double);

		Student(char const * ,int, double);
		Student(Student &);  // copy constructor

		~Student();

		// member operator functions

		Student & operator=(const Student &);
		Student & operator+=(const int &);
		Student & operator++(); // prefix
		Student operator++(int); // postfix

	// helper operator functions

	friend bool operator==( const Student &, const Student &);
	friend ostream & operator<<(ostream &, const Student &);
	friend istream & operator<<(istream &, Student &);
};

Student::Student(char const *n, int i, double g)
{
	setname(n);
	setid(i);
	setgrade(g);
}

Student::Student(Student &t)
{
	name = new char[strlen(t.name)+1];
	strcpy(name, t.name);
	id = t.id;
	grade = t.grade;
}

Student::~Student()
{
	delete [] name;
}


void Student::print()
{
	cout << "\tname: " << name << endl;
	cout << "\tID: " << id << endl;
	cout << "\tGrade " << grade << endl;
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

void Student::setgrade(double g)
{
	grade = g;
}

// member operator implementation

Student & Student::operator=(const Student &d)
{
	id = d.id;
	grade = d.grade;
	delete [] name;

	name = new char[strlen(d.name)+1];
	strcpy(name,d.name);

	return *this;
}

Student & Student::operator+=(const int &g)
{
	grade += g;
	return *this;
}

Student & Student::operator++()
{
	grade++;
	return *this;
}

Student Student::operator++(int)
{
	Student temp = *this;
	grade++;
	return temp;
}

// helper operator implementation

bool operator==( const Student &s, const Student &t)
{
	return s.id == t.id;
}

ostream & operator<<(ostream & os, const Student &s)
{
	os << "\tname: " << s.name << endl;
	os << "\tID: " << s.id << endl;
	os << "\tGrade " << s.grade << endl;
	return os;
}

istream & operator>>(istream & is, Student &s)
{
	char tmp_name[200];
	int tmp_id;
	double tmp_grade;


	cout << "\tname: ";
	is >> tmp_name;

	cout << "\tID: ";
	is >> tmp_id;

	cout << "\tGrade ";
	is >> tmp_grade;

	s = Student(tmp_name,tmp_id, tmp_grade);

	return is;
}

int main()
{
	Student a("John",119, 75.6);

	cout << "a:" << endl;
	a.print();

	cout << "Student b = a" << endl;
	Student b = a; // copy constructor will be called

    cout << "b:" << endl;
    b.print();


	Student c("Sarah",115, 75.6);

	cout << "c:" << endl;
	c.print();

	cout << "a = c" << endl;
	a = c;

	cout << "a:" << endl;
	a.print();

	cout << "a += 4" << endl;
	a += 4;

	cout << "a:" << endl;
	a.print();

	cout << "(a++).print()" << endl;
	(a++).print();

	cout << "(++a).print()" << endl;
	(++a).print();

	cout << "cin >> a" << endl;
	cin >> a ;

	cout << "cout << a" << endl;
	cout << a;

	cout << (a == b);
	return 0;
}
