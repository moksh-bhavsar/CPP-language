// How to define an exception class

#include <iostream>

using std::cin;
using std::cout;

class NoMilk
{
public:
    NoMilk( ) {}
    NoMilk(int howMany) : count(howMany) {}
    int getCount( ) const { return count; }
private:
    int count;
};

int main( )
{
    int donuts, milk;
    double dpg;
    try
    {
        cout << "Enter number of donuts: ";
        cin >> donuts;
        cout << "Enter number of glasses of milk: ";
        cin >> milk;

        if (milk <= 0)
            throw NoMilk(donuts);

        dpg = donuts / double(milk);
        cout << donuts << " donuts.\n";
        cout << milk << " glasses of milk.\n";
        cout << "You have " << dpg;
        cout << " donuts for each glass of milk.\n";
    }
    catch(NoMilk e)
    {
        cout << e.getCount( ) << " donuts, and No Milk!\n" << "Go buy some milk.\n";
    }
    cout << "End of program.\n";

    return 0;
}

