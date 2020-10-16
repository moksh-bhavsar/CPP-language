#include <iostream>
#include <list>
#include <map>
#include <set>

using namespace std;

void printList(list<string> z);

void hist(list<string> x);

list<string> merge(list<string> x, list<string> y);

int main() 
{ 
	list<string>  x = {"Alan","Alice", "Ben", "Elena", "John", "Alan", "Ben", "Alan"};
	 
	list <string> y = {"Ben", "John", "Ben", "Elena", "Richard", "Jeremy"};   
		
	list<string> z;
	 
	hist(x);
	  
	z = merge(x,y);
		
	printList(z);
	 
	return 0; 
}

void printList(list<string> z){
	list<string>::const_iterator i;
	
	for (i = z.cbegin(); i!=z.cend(); i++){
		cout << *i << " ";
	}
	cout << endl;
}

void hist(list<string> x){
	map<string, int> number;	// using map to count occurence of each string
	list<string>::const_iterator i;

	for (i = x.cbegin(); i != x.cend(); i++){	
		if (number.find(*i) == number.end()){
			number[*i] = 1;
		}
		else{
			number[*i] = number[*i] + 1; 
		}
	}
	
	// printing the map
	map<string, int>::iterator j;
    for (j = number.begin(); j != number.end(); ++j) 
    {
        cout << j->first << " , " << j->second << endl;
    }
}

list<string> merge(list<string> x, list<string> y){
	list<string> temp; // the required return thing
	set <string> temp2;	// using set(temp2) to avoid duplication
	list<string>::const_iterator i;
	
	// inserting string from first list to set
	for (i = x.cbegin(); i!=x.cend(); i++){
		temp2.insert(*i);
	}
	
	// inserting string from second list to set
	for (i = y.cbegin(); i!=y.cend(); i++){
		temp2.insert(*i);
	}
	
	set<string>::reverse_iterator j;
	// inserting string from temp2 to temp, i.e from set to list
	for (j = temp2.rbegin(); j!= temp2.rend(); j++){
		temp.push_front(*j);
	}

	return temp;
	
}