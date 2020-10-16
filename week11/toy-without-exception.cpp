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

    if (milk <= 0){
        cout << donuts << " donuts, and No Milk!\n" << "Go buy some milk.\n";
    }
    else{
        dpg = donuts / double(milk); 
        cout << donuts << " donuts.\n";
        cout << milk << " glasses of milk.\n";
        cout << "You have " << dpg << " donuts for each glass of milk.\n";
    }

    cout << "End of program.\n";

    return 0;

}