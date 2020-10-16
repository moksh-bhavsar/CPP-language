#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream fin;
  ofstream fout;

  fin.open("infile.txt");

  int x,i=0;

  if (fin.fail()){
    cerr << " Cannot open the input file! " << endl;
    return 1;
  }

  fout.open("outfile.txt");
  if (fout.fail()){
    cerr << " Cannot open the output file! " << endl;
  }

  while (fin>>x){   // we can use fin.get(x) instead to get the same output in file as input and it reads whitespace as well as
    cout << "Number " << i++ << " is: " << x << endl;
  }

  fin.close();
  fout.close();

  return 0;
}
