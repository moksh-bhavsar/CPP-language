// str.cpp
#include "str.h"
#include <cstring>

str::str() // Default constructor
{
  _buf = nullptr;
  _n = 0;
}

str::str(char ch)
{
   _n = 1;
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = c_str[i];
}

str::str(const str &s)   // Copy constructor
{

 // Your code is here	
 _buf = new char[strlen(s._buf)+1];
 strcpy(_buf, s._buf);
 _n = s._n;

}
str::~str()
{
  if (_buf) 
    delete [] _buf;
}

void str::print()
{
  for (int i = 0; i < _n; ++i) 
    cout << _buf[i];
  cout << endl;
}


void str::clear()
{
  // Your code is here  // Hint: after "clear" the string is like what the default constructor creates 
  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s)
{
  // Your code is here 
  
	char* _buf1 = new char[_n + s._n + 1];
	for (int i=0; i < _n + s._n; i++){
		if (i < _n){
			_buf1[i] = _buf[i];
		}
		else{
			_buf1[i] = s._buf[i - _n];
		}
	}		
	delete _buf;
	_buf = new char[strlen(_buf1)];
	_n = _n + s._n;
	for (int i=0; i<_n; i++){
		_buf[i] = _buf1[i];
	}
	delete _buf1;	

}

void swap(str& x, str& y)
{
  // Your code is here
  char *temp = x._buf;
  int temp2 = x._n;
  x._buf = y._buf;
  y._buf = temp;
  x._n = y._n;
  y._n = temp2;
  }