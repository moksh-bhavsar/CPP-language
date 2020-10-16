#include <iostream> // Including the libraries
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
  char *charShift;    // Declaring the variables
  int shift;
  char c;
  charShift = argv[2];    // Here argv[2] is 'shift'
  shift = *(charShift) - '0';   // the shift entered in command line is char and thus converting into int

  // Checking to see if enough command line arguments are not presented
  if ((argc != 3) && (argc != 5)){
    cout << "ERROR: need either 3 or 5 arguments!!" << endl;
    return 0;
  }

  // Checking if the user wants encryption(e) or decryption(d)
  if (argv[1][1] == 'e'){
    shift = shift;
  }
  else if (argv[1][1] == 'd'){
    shift = (-1)*shift;
  }

  // Using if to implement caesar cipher using file redirection
  if (argc == 3){
    // Reading from the input file and then encrypting or decrypting and then writing into output file
    while(cin.get(c)){
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

      cout.put(c);
    }
  }

  // Using file stream to implement caesar cipher
  else if (argc == 5){
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

  }

  return 0;
}
