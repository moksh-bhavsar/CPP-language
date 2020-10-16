// Constant Iterator
#include <iostream> 
#include <list> 

using namespace std;

int main() 
{
    list<string> names;
    names.push_back("John");
    names.push_back("Amanda");

    list<string>::const_iterator i;
    for (i = names.cbegin(); i != names.cend(); ++i) 
    {
        cout << *i << endl;
    }
    return 0; 
}