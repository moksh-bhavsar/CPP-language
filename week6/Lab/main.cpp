// main.cpp

#include "str.h"

int main()
{
  cout << "TEST PROGRAM !!" << endl;
  
  str s1("Hello"); 
  
  cout << "s1 = "; 
  s1.print();

  str s2 = s1;
  
  cout << "s2 = "; 
  s2.print();

  str s3("!!!"); 
  
  cout << "s3 = "; 
  s3.print();

  cout << "DO s1.clear()" << endl;
  s1.clear();
  cout << "\ts1 = "; 

  s1.print(); 
  
  cout << "DO s2.append(s3)" << endl;
  s2.append(s3);

  cout << "\ts2 = "; 
  s2.print();

  cout << "DO swap(s2,s3)" << endl;
  swap(s2,s3);

  cout << "\ts2 = "; 
  s2.print();

  cout << "\ts3 = "; 
  s3.print();

  return 0;
}