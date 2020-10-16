// main.cpp

#include "time.h"

int main()
{
    Time t1(23,3,59),t2(1,4,9),t3;
    t3 = t1 + t2;      //adding of two time object using '+' operator

    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl; 
    cout << "t1 + t2 = " << t3 << endl;;

    cout << "t1++ = " << t1++ << endl;
    cout << "t1 = " << t1 << endl;
    cout << "++t1 = " << ++t1 << endl;
    cout << "t1 = " << t1 << endl; 

    cout << "Reading  t1 ..." << endl;
    cin >> t1;
    cout << "t1 = " << t1 << endl;

    return 0;
}