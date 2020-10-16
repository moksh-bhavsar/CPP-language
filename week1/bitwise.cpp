#include <iostream>

using namespace std;

int main(){

  char x = 10;
  char y = 2;

  cout << "(x & y) = " << (x & y) << endl;
  cout << "(x | y) = " << (x | y) << endl;
  cout << "(x ^ y) = " << (x ^ y) << endl;
  cout << "(~x) = " << (~x) << endl;
  cout << "(x >> 3) = " << (x >> 3) << endl;
  cout << "(x << 3) = " << (x << 3) << endl;

  return 0;
}
