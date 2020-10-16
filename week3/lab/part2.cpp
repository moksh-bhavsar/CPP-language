#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
  char *charShift;
  int shift;
  charShift = argv[2];
  //cout << charShift;
  shift = *(charShift) - '0';

  if (argc < 5){
    cout << "ERROR: needed more arguments!!" << endl;
    return 0;
  }
  else if(argc > 5){
    cout << "ERROR: more argument given!!" << endl;
    return 0;
  }

  ifstream fin;
  ofstream fout;

  fin.open(argv[3]);

  char c;

  if (fin.fail()){
    cerr << "Cannot open the input file" << endl;
    return 0;
  }

  fout.open(argv[4]);

  if (fout.fail()){
    cerr << "Cannot open the output file" << endl;
    return 0;
  }

  if (argv[1][1] == 'e'){
    shift = shift;
    cout << "Encrypting..." << endl;
  }
  else if (argv[1][1] == 'd'){
    shift = (-1)*shift;
    cout << "Decrypting..." << endl;
  }

  while(fin.get(c)){
    int index = int(c);    // Here, index means the ascii value of the character
    // Condition when index variable goes less than 65, i.e. becomes less than 'A'
    if (index >=65 && index <= 90){
      index = index + shift;    // Increasing or decreasing the ascii value as per the user input
      if (index < 65){
        int remainder = 65 - index;
        index = 91-remainder;
      }
      // Condition when index variable goes more than 90, i.e. becomes more than 'Z'
      else if(index >90){
        int remainder = index - 90;
        index = 64 + remainder;
      }
    }
    c = static_cast<char>(index); // Encrypting the plaintext character by changing its ascii value and again changing back to character

    fout.put(c);
  }

  fin.close();
  fout.close();

  if (argv[1][1] == 'e'){
    cout << "Encryption done!!" << endl;
  }
  else if (argv[1][1] == 'd'){
    cout << "Decryption done!!" << endl;
  }

  return 0;
}
