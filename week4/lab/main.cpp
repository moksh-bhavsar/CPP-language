#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

#include "count.h"  // including header file

int main(int argc, char** argv) // using command line arguments
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 1 and 10000\n";
    cerr << "\tExiting.";
    return -1;
  }

  int n = atoi(argv[1]);  // to check if user has enter number between a given range
  if (n < 1 || n > 10000) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 1 and 10000\n";
    cerr << "\tExiting.";
    return -2;
  }

  srand(time(NULL));  // seeding the rand function

  //////////////////////////////////////////////
  //
  // TODO
  // Change the following line to char* arr = new char[n];
  //
  //////////////////////////////////////////////

  // Creating two dynamic arrays
  char *arr = new char[n];
  int *counts = new int[26];

  //////////////////////////////////////////////
  //
  // TODO
  // Change the following lines such arr
  // contains letter A - Z.   The letters will be
  // randomly generated.
  //
  //////////////////////////////////////////////

  // randomly generating characters from A-Z
  for (int i=0; i<n; ++i) {
    arr[i] = 'A' + rand()%26;
  }

  // displaying the array of randomly generated characters
  for (int i=0; i<n; ++i){
    cout << arr[i] << ' ';
  }
  cout << endl;

  count(arr, n, counts);  // calling count function from count.cpp and count.h

  char c = 'A';
  int j = 0;
  for (int i=0; i<26; ++i){   // displaying the number of characters in the array
    int char_to_array = int(c) + j;
    cout << static_cast<char>(char_to_array) << " : " << counts[i] << endl;;
    j++;
  }
  cout << endl;

  // deleting the arrays after use
  delete [] arr;
  delete [] counts;

  return 0;
}
