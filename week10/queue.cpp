// queue
#include <iostream> 
#include <queue> 

using namespace std;

int main() 
{
    queue<string> names;
    names.push("John");
    names.push("Amanda");
    names.push("Jessi");
    names.push("Sarah");  

    cout << "\nPrinting the stack:" << endl;

    while (!names.empty()) 
    {
        cout << names.front() << endl;
		names.pop();
    }

    cout << endl;
    return 0; 
}