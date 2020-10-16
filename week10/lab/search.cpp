#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//#define DEBUG

int main(int argc, char** argv)
{
  // code goes here 
  
	if (argc >3){
		cerr << "ERROR: more arguments found!!" << endl;
		return 0;
	}
	else if(argc <3){
		cerr << "ERROR: less arguments given" << endl;
		return 0;
	}
	
	ifstream fin;
	fin.open(argv[1]);
	
	if (fin.fail()){
		cerr << "ERROR: Inadequate memory!!!" << endl;
		return 0;
	}
	
	int count = 0;
	int size = 0;
	
	// Calculating size of the string to be found
	while(argv[2][size] != '\0'){
		size++;
	}
	
	// Using if-else to check whether the argument was a character or a string
	if (size != 1){ // if the argument was string
		string x;
		while(fin >> x){
			if (x == argv[2]){
				count++;
			}
		}
	}else{	// if the argument was character
		char x;
		while(fin >> x){
			if (x == argv[2][0]){
				count++;
			}
		}
	}
	
	cout << "Reading " << argv[1] << endl;
	
	cout << argv[2] << " was found " << count << " times." << endl;
	
	return 0;
}