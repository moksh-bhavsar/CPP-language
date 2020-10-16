#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

class Filter
{
protected:
  string _name;

public:  
  Filter(const string& name) : _name(name) {}
  virtual ~Filter() {};

  virtual string apply(const string& input) = 0;

  string get_name() { return _name; }
};

class Capitalize: public Filter{
	
public:
	Capitalize(): Filter("Capitalize") {}
	string apply(const string& input);
	~Capitalize() {};
};

string Capitalize::apply(const string&input){
	
	string temp;
	
	temp = input;
	
	for (int i=0; i< temp.length();i++){
		int toCapital = int(temp.at(i));
		if ((toCapital >=97) && (toCapital <= 122)){
			toCapital = toCapital - 32;
		}
		temp.at(i) = static_cast<char>(toCapital);
	}
	
	return temp;
}

class CapitalizeFirstLetter: public Filter{
	
public:
	CapitalizeFirstLetter() : Filter("CapitalizeFirstLetter") {}
	string apply(const string& input);
	~CapitalizeFirstLetter() {};
	
};

string CapitalizeFirstLetter::apply(const string& input){
	string temp;
	
	temp = input;
	
	for (int i=0; i<temp.length(); i++){
		if (((temp.at(i) <= 'z') && (temp.at(i) >= 'a')) || ((temp.at(i) <= 'Z') && (temp.at(i) >= 'A'))){
			temp.at(i) = toupper(temp.at(i));
			break;
		}
	}
	return temp;
}	

class CapitalizeFirstLetterOfEveryWord: public Filter{

public:
	CapitalizeFirstLetterOfEveryWord() : Filter("CapitalizeFirstLetterOfEveryWord") {}
	string apply(const string& input);
	~CapitalizeFirstLetterOfEveryWord() {};
};

string CapitalizeFirstLetterOfEveryWord::apply(const string& input){
	string temp;

	temp = input;
	
	temp.at(0) = toupper(temp.at(0));
	
	for (int i=0; i<temp.length()-1; i++){
		if ((int(temp.at(i)) == 32)){
			i++;
			if ((temp.at(i) >= 'a') && (temp.at(i) <= 'z')){
				temp.at(i) = static_cast<char>(int(temp.at(i))-32);
			}
		}			
	}
	
	return temp;
}

class Obenglobish: public Filter{

public:
	Obenglobish():Filter("Obenglobish") {}
	string apply(const string& input);
	~Obenglobish() {};
};

string Obenglobish::apply(const string& input){
	string temp = input;
	int numberOfVowels = 0;
	
	for (int i=0; i<temp.length(); i++){
		if ((tolower(temp.at(i)) == 'a') || (tolower(temp.at(i)) == 'e') || (tolower(temp.at(i)) == 'i') || (tolower(temp.at(i)) == 'u')  || (tolower(temp.at(i)) == 'o')){
			numberOfVowels++;
		}
	}
	
	int sz = temp.length();

	temp.resize(sz + 2*numberOfVowels);
	
	for (int i=0; i<temp.length(); i++){
		if ((tolower(temp.at(i)) == 'a') || (tolower(temp.at(i)) == 'e') || (tolower(temp.at(i)) == 'i') || (tolower(temp.at(i)) == 'u') || (tolower(temp.at(i)) == 'o')){
			for (int j = sz-1; j >= i; j--){
				temp.at(j+2) = temp.at(j);
			}
			temp.at(i) = 'o';
			temp.at(i+1) = 'b';
			i+=2;
			sz = sz + 2;
		}
	}
	
	return temp;
}

class ReverseString: public Filter{
	public:
		ReverseString(): Filter("ReverseString") {}
		string apply(const string& input);
		~ReverseString() {};
};

string ReverseString::apply(const string& input){
	string temp = input;
	
	for(int i=0; i<temp.length(); i++){
		temp.at(temp.length() - i - 1) = input.at(i);
	}
	
	return temp;
}

class ToSmall: public Filter{
	public:
		ToSmall(): Filter("ToSmall") {}
		string apply(const string& input);
		~ToSmall() {} ;
};

string ToSmall::apply(const string& input){
	string temp = input;
	
	for (int i=0; i<temp.length(); i++){
		temp.at(i) = tolower(temp.at(i));
	}
	
	return temp;
}

class Randomize:public Filter{
	public:
		Randomize(): Filter("Randomize") {}
		string apply(const string& input);
		~Randomize() {} ;
};

string Randomize::apply(const string& input){
	string temp = input;
	
	srand(time(NULL));
	
	for (int i=0; i<temp.length(); i++){
		int random1 = rand()%(temp.length());
		int random2 = rand()%(temp.length());
		if(int(temp.at(random1)) != 32){
			if (int(temp.at(random2 ))!= 32){
				char temp1 = temp.at(random1);
				temp.at(random1) = temp.at(random2);
				temp.at(random2) = temp1;
			}
		}
		
	}

	return temp;
}

int main(){
	const int num_filters = 7;
	Filter* filters[num_filters];

	filters[0] = new Capitalize();
	filters[1] = new CapitalizeFirstLetter();
	filters[2] = new CapitalizeFirstLetterOfEveryWord();
	filters[3] = new Obenglobish();
	filters[4] = new ReverseString();
	filters[5] = new ToSmall();
	filters[6] = new Randomize();
	  
	string input;
	cout << "Enter string: ";  getline(cin, input);
	  
	cout << "Input string: " << input << endl;
	for (int i=0; i<num_filters; ++i) {
	  cout << "Filter name:  " << filters[i]->get_name() << endl;
	  cout << "Output:       " << filters[i]->apply(input) << endl; 
	}

	for (int i=0; i<num_filters; ++i) delete filters[i];

	return 0;
}	