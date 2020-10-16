//Program to demonstrate use of the generic find function. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print(vector<char>::iterator , vector<char>::iterator);

int main()
{
    vector<char> v = {'X', 'A', 'N', 'B', 'X', 'Z'};
    
    vector<char>::iterator where;

    print(v.begin(), v.end());
    
    where = find(v.begin(),v.end(), 'N');
    
    cout << "v.begin() to where" << endl;
    print(v.begin(), where);

    cout << "Count of X is : ";
    cout << count(v.begin(),v.end(), 'X') << endl;


    vector<char> w(6); // 6 is the size of vector
    
    copy(v.begin(), v.end(), w.begin());
    
    print(w.begin(), w.end());

    reverse(v.begin(), v.end());
    
    cout << "Reverse: " ;
    print(v.begin(), v.end());   

    cout << endl;
    return 0;
}

void print(vector<char>::iterator i, vector<char>::iterator j)
{
    for (vector<char>::iterator p = i; p != j; p++)
        cout << *p;
    cout << endl;
}