// stack
#include <iostream> 
#include <stack> 

using namespace std;

int main() 
{
    stack<string> names;
    names.push("John");
    names.push("Amanda");
    names.push("Jessi");
    names.push("Sarah");  

    cout << "\nPrinting the stack:" << endl;

    while (!names.empty()) 
    {
        cout << names.top() << endl;
		names.pop();
    }

    cout << endl;
    return 0; 
}