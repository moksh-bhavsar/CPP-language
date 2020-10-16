// str.h

#ifndef __str_h__
#define __str_h__

#include <iostream>

using namespace std;

class str
{
  private:
    char* _buf;  // pointer to the underlying storage
    int _n;      // length of the string

  public:
    // constructors of various forms
    str();      
    str(char ch);
    str(const char* c_str);

    // copy constructor 
    str(const str &);

    // lets not forget the destructor
    ~str();

    // function for finding length of the string
    int length() const { return _n; } // here const means that length function cannot change the object's data members

    // function for checking if string is null string
    bool is_empty() const { return _n == 0; }

    void print();
  
    // clear erases the contents of the string, which becomes an empty/null string
    void clear();

    // append extends the string by appending additional characters at the end of its current value
    void append(const str& str);

  // swap function exchanges the values of two strings
  friend void swap(str &, str &);
};

#endif