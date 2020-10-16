// Q2.cpp 

#include <iostream>
#include <cstring>

 

using namespace std;

 

class Movie{       

	// Define data members
	public:
		char *name = new char[200];
		int rating;
		int year;

    // default constructor
		Movie();

	// second constructor
		Movie(string movieName, int movieRating, int movieYear);

    // copy constructor
		Movie (Movie &t);
 
    // Destructor
		~Movie();
 
    // overload operator=
		Movie operator=(const Movie &t);

	// overload operator++
		Movie& operator++();
 
    // overload operator<<
	friend ostream& operator<<(ostream& os, Movie &t);

};

// Implement requested function here
Movie::Movie(){
	name = nullptr;
	rating = 0;
	year = 0;
}

Movie::Movie(string movieName, int movieRating, int movieYear): rating(movieRating), year(movieYear){
	for (int i=0; i<movieName.length(); i++){
		name[i] = movieName.at(i);
	}
}

Movie::Movie( Movie &t){
	if (name)
		delete name;
	
	name = new char[strlen(t.name)+1];
	
	for (int i=0; i<strlen(t.name);i++){
		name[i] = t.name[i];
	}
	
	this->year = t.year;
	this->rating = t.rating;
}

Movie::~Movie(){
	if (name)
		delete name;
}

Movie Movie::operator=(const Movie &t){
	if (name)
		delete name;
	
	name = new char[strlen(t.name)+1];
	
	for (int i=0; i<strlen(t.name);i++){
		name[i] = t.name[i];
	}
	
	this->year = t.year;
	this->rating = t.rating;
	
	return *this;
}

Movie& Movie::operator++(){
	this->rating++;
	
	return *this;
}

ostream& operator<<(ostream& os, Movie &t){
	if (t.name== nullptr){
		os << "Empty Object" << endl;
	}
	
	else{
		os << "Name: " << t.name << endl;
		os << "Rating: " << t.rating << endl;
		os << "Year: " << t.year << endl;
	}
	
	return os;
}

// Do not change the main

int main()

{

    Movie x("Titanic", 4, 2000);

    Movie y = x;

    Movie z;

     

    z = y;

 

    cout << y;

    cout << ++z;

 

	return 0;

}