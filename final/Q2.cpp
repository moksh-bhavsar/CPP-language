#include <iostream>
#include <string>

using namespace std;

class Document
{
    public:
    Document() 
    { 
        text =""; 
    }
    Document(string text)  
    { 
		this->text = text; 
    }
    string getText() const
    { 
        return this->text;  
    }
    // Write your code here
	void virtual print()  = 0; //Creating a pure virtual function
  
private:
    string text;
}; 

// Creating class Email derived from Document class
class Email : public Document{
	// Creating member variables
	private:
	string sender;
	string	recipient;
	string title;
	
	public:
	Email() 	//Default Constructor
	{ 
		sender = "";
		recipient = "";
		title = "";
	}
	
	// Constructor
	Email(string tex, string s, string r, string t): Document(tex){
		this->sender = s;
		this->recipient = r;
		this->title = t;
	}
	
	// getter functions
	string getSender() { return sender; }
	string getRecipient() {return recipient; }
	string getTitle() { return title; }
	
	// setter functions
	void setSender(string s);
	void setRecipient(string r);
	void setTitle(string t);
	
	void print() ;
	
};

void Email::setSender(string s){
	this->sender = s;
}

void Email::setRecipient(string r){
	this->recipient = r;
}

void Email::setTitle(string t){
	this->title = t;
}

// overriding print of base class to print in required format
void Email::print() {
	cout << "Email Information:" << endl;
	cout << "=====================" << endl;
	cout << "Sender:" << this->getSender() << endl;
	cout << "Recipient:" << this->getRecipient() << endl;
	cout << "Content:" << this->getText() << endl;
}

// a function to find a word in text of Document class
bool ContainsKeyword(Document *d, string s){
	bool contain = false;
	string mainText;
	mainText = d->getText();	// Creating new string and giving it the value of the title
	size_t found = mainText.find(s); // for finding if the string contains the word
	
	if (found != std::string::npos){ // return npos if the string does not contain word
		contain = true;
	}
	else {
		contain = false;
	}
	return contain;
}

int main()
{ 
  Document *d;
  
  d = new Email("Programming in C++", "Larry", "Curly", "Programming");
  
  d->print(); // Test for print function
 
   // Test for ContainsKeyword function

 if (ContainsKeyword(d,"C++")) 
      cout << "C++ is in the e-mail." << endl; 
  else 
      cout << "C++ is NOT in the e-mail." << endl;
 
  return 0;
}