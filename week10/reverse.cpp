// Reverse Iterator
#include <iostream> 
#include <list> 

using namespace std;

int main() 
{
    list<string> names;
    names.push_back("john");
    names.push_back("amanda");

    list<string>::reverse_iterator i;
    for (i = names.rbegin(); i != names.rend(); ++i) 
    {
        cout << *i << endl;
    }
    return 0; 
}