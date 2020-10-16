// map
#include <map> 
#include <iostream> 
#include <string> 

using namespace std;

int main() 
{
    map<string, int> super_heros;
    super_heros["batman"] = 32;
    super_heros["wolverine"] = 137;
    super_heros["jean gray"] = 25;
    super_heros["superman"] = 35;

    map<string, int>::iterator i;
    for (i = super_heros.begin(); i != super_heros.end(); ++i) 
    {
        cout << "Age of " << i->first << " is " << i->second << endl;
    }

    return 0; 
}