// basic exception example

#include <iostream>
using namespace std;


int main() 
{
    
    int donuts, milk;
    
    double dpg;
    cout << "Enter number of donuts:";
    cin >> donuts;
    cout << "Enter number of glasses of milk:";
    cin >> milk;

    // put the code that you want to catch its exceptions
    try{
        if (milk <= 0)
            throw donuts;
        dpg = donuts / double(milk); 
        cout << donuts << " donuts.\n";
        cout << milk << " glasses of milk.\n";
        cout << "You have " << dpg << " donuts for each glass of milk.\n";
    }
    
    // catch block deals with the exception
    catch(int e){
                cout << donuts << " donuts, and No Milk!\n" << "Go buy some milk.\n";
    }

    cout << "End of program.\n";

    return 0;

}