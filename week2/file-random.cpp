#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
 {
 	// Task 1: writing numbers to a binary file

  ofstream fout1("outfile.b",ios::binary);

 	if (fout1.fail())
 	{
 		cerr << " Cannot open the output file!" << endl;
 		return 1;
 	}

 	for (int i = 0; i < 20; ++i)
 	{
 		fout1.write((char *) &i,sizeof(int));
 	}

 	fout1.close();


 	// Task 2: reading numbers from a binary file

 	ifstream fin1("outfile.b",ios::binary);

	if (fin1.fail())
 	{
 		cerr << " Cannot Input the output file!" << endl;
 		return 1;
 	}

 	int x;

 	while(fin1.read((char *)&x,sizeof(int)))
 	{
 		cout << x << endl;
 	}

    fin1.close();

 	// Task 3: reading 5'th number

	fstream fin2("outfile.b",ios::binary|ios::in | ios::out);

 	fin2.seekg(5* sizeof(int)); // set a place for getting the input
 	fin2.read((char *)&x,sizeof(int));
    cout << "The 5'th number is " << x << endl;


 	// Task 4: writing numbers to a certain place in a binary file

 	x = 8;

 	fin2.seekp(5* sizeof(int)); // set a place for putting the output

  fin2.write((char *)&x,sizeof(int));

  fin2.seekg(5*sizeof(int));
  fin2.read((char*) &x, sizeof(int));
  cout << "The 5'th number is " << x << endl; 

    fin2.close();

 	return 0;

 }
