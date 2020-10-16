
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 	ofstream fout;

 	int x = 1234567;

 	fout.open("out.txt");
 	if (fout.fail())
 	{
 		cerr << " Cannot open the output file!" << endl;
 		return 1;
 	}

 	fout << x;

 	fout.close();


 	fout.open("out.b",ios::binary);
 	if (fout.fail())
 	{
 		cerr << " Cannot open the output file!" << endl;
 		return 1;
 	}


 	fout.write((char *) &x, sizeof(int));

 	fout.close();



 	 return 0;

 }
