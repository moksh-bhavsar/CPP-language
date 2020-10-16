// set
#include <set> 
#include <iostream> 
#include <string> 

using namespace std;

int main() 
{
    set<string> super_heros;
    
    super_heros.insert("batman");
    super_heros.insert("wolverine");
    super_heros.insert("jean gray");
    super_heros.insert("superman");

    set<string>::iterator p;

    cout << "Set contains:" << endl;
    for (p = super_heros.begin(); p != super_heros.end(); ++p) 
    {
        cout << *p << endl;
    }

    cout << "Is batman is in the set?" << endl;
    if (super_heros.find("batman")==super_heros.end( ))
        cout << " no " << endl;
    else
        cout << " yes " << endl;

    return 0; 
}