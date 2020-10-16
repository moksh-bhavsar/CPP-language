#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
  char c;
  int sum_of_even;

  ifstream fin;
  fin.open(argv[1]);

  int x = 48; // ascii value of 0
  //cout << static_cast<char>(x) << endl;

  while(fin.get(c)){
    int num = c - '0';
    //cout << num << endl;
    if ((num%2 == 0) && (num>= 0) && (num <=9)){
      sum_of_even = sum_of_even + num;
    }
  }

  cout << sum_of_even << endl;

  return 0;
}
