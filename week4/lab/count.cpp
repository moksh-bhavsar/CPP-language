#include <iostream>
#include "count.h"  // #including count.h file

using namespace std;

// defining function declared in count.h
void count(char arr[], int n, int counts[]){
  // the function takes a character form arr[] and displays the number of times
  // it is presented into counts[] which is an array of size 26
  for (int i=0; i<n; i++){
    char c = arr[i];
    int index = c - 'A';  // assigning count of a specific character a specific index value
    counts[index]++;  // increasing the count each time we encounter the character
  }
}
