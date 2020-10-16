// time.h

#ifndef __time_h__
#define __time_h__

#include <iostream>

using namespace std;

class Time
{
    private:
        
        int hour; 
        int minute;
        int second;  
    
    public:

        Time(int=0, int=0, int=0);
     
        //overloading '+' operator
        Time operator+(Time);  
        Time & operator++();     // prefix
        Time operator++(int);  // postfix 

    friend istream & operator>>(istream &, Time &);
    friend ostream & operator<<(ostream &, const Time &);
};

#endif