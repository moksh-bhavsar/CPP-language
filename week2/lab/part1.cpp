#include <iostream> // Including libraries
#include <cstring>

using namespace std;

int main(){
  char a[100];    // Creating an character array of 100 characters
  int shift;      // Creating a variable shift for encryption

  cout << "Enter shift +/- 26: " << endl;
  cin >> shift;

  cout << "Enter plaintext message (A-Z only, no spaces): " << endl;
  cin >> a;

  cout << endl;

  // Encrypting the message using the ASCII values of the characters
  for (int i=0; i< strlen(a); i++){
    int index = int(a[i]);    // Here, index means the ascii value of the character
    index = index + shift;    // Increasing or decreasing the ascii value as per the user input
    // Condition when index variable goes less than 65, i.e. becomes less than 'A'
    if (index < 65){
      int remainder = 65 - index;
      index = 91-remainder;
    }
    // Condition when index variable goes more than 90, i.e. becomes more than 'Z'
    else if(index >90){
      int remainder = index - 90;
      index = 64 + remainder;
    }
    a[i] = static_cast<char>(index); // Encrypting the plaintext character by changing its ascii value and again changing back to character
  }

  cout << "ciphertext :" << a << endl;

  shift = shift*(-1); // Using for decryption

  // Decrypting the meassage after its encryption
  for (int i=0; i< strlen(a); i++){
    int index = int(a[i]);
    index = index + shift;
    if (index < 65){
      int remainder = 65 - index;
      index = 91-remainder;
    }
    else if(index >90){
      int remainder = index - 90;
      index = 64 + remainder;
    }
    a[i] = static_cast<char>(index);
  }

  cout << "plaintext :" << a << endl;

  return 0;
}
