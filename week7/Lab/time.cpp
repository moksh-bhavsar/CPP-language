// time.cpp

#include "time.h"
#include <iostream>

Time::Time(int h, int m, int s)
{ 
    hour=h, minute=m; second=s;
} 

Time Time::operator+(Time t)  
{
    // your code is here
	Time temp;	// Creating a temporary object of time class
	
	temp.second = second + t.second;
	temp.minute = minute + t.minute;
	temp.hour = hour + t.hour;
	
	// Using if statements to check if the values of second, minute and hour do not overflow
	if (temp.second >= 60){
		temp.second = temp.second - 60;
		temp.minute++;
	}
	
	if (temp.minute >= 60){
		temp.minute = temp.minute - 60;
		temp.hour++;
	}
	
	if (temp.hour >= 24){
		temp.hour = temp.hour - 24;
	}		
	
	return temp;
}

Time & Time::operator++()
{
    // your code is here 
	Time increment;		//Creating an object of class time that increments the second by 1;
	increment.hour = 0;
	increment.minute = 0;
	increment.second = 1;
	
	*this = *this + increment; // Using overloaded operator+ to increment the time
	
	return *this;
}

Time Time::operator++(int)
{
    // your code is here 
	Time temp = *this;		// Initializing temp to the old value of the object
	Time increment;
	increment.hour = 0;
	increment.minute = 0;
	increment.second = 1;
	
	*this = *this + increment;	// Incrementing the value of the object
	
	return temp;
}

ostream & operator<<(ostream & out, const Time & t)
{
    // your code is here 
	// Using if statements to determine when to write '0's in the output
	if (t.hour < 10){
		out << "0" << t.hour;
	}
	else
		out << t.hour;
	
	out << ":";
	
	if (t.minute < 10){
		out << "0" << t.minute;
	}
	else
		out << t.minute;
	out << ":";
	
	if (t.second < 10){
		out << "0" << t.second;
	}
	else
		out << t.second;
	
	out << endl;
	return out;
}


istream & operator>>(istream & in, Time & t)
{
    // your code is here 
	int temp_hour;
	int temp_minute;
	int temp_second;
	bool valid_input = false;
	
	// using while loop and if statements to check if the user has given input in the desired range
	while (!valid_input){
		cout << "Enter the hour(0-23): " << endl;
		in >> temp_hour;
		if ((temp_hour >= 0)&& (temp_hour <= 23)){
			t.hour = temp_hour;
			
			cout << "Enter the minute(0-59): " << endl;
			in >> temp_minute;
		
			if ((temp_minute <= 59) && (temp_minute >= 0)){
				t.minute = temp_minute;
				
				cout << "Enter the second(0-59): " << endl;
				in >> temp_second;
				
				if ((temp_second >= 0) && (temp_second <=59)){
					t.second = temp_second;
					valid_input = true;
				}
				else{
					cout << "ERROR: Invalid Input!!! Try Again." << endl;
					valid_input = false;
				}
			}
			else{
				cout << "ERROR: Invalid Input!!! Try Again." << endl;
				valid_input = false;
			}
		}
		else{
			cout << "ERROR: Invalid Input!!! Try Again." << endl;
			valid_input = false;
		}
	}
	return in;
}