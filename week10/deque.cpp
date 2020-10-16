// deque
#include <iostream> 
#include <deque> 

using namespace std;

int main() 
{
    deque<string> names;
    names.push_front("John");
    names.push_front("Amanda");
    names.push_back("Jessi");
    names.push_back("Sarah");  

    cout << "\nPrinting the deque:" << endl;

    while (!names.empty()) 
    {
        cout << names.front() << endl;
		names.pop_front();
    }

    cout << endl;
    return 0; 
}