// Basic Student class

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
};

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

	return 0;
}
