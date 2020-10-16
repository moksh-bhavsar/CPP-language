#include "SavingsAccount.h"
#include<iomanip>

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ) : Account( initialBalance ) 
{
	// your code
	interestRate = rate;
}

double SavingsAccount::calculateInterest() {
	// your code
	double interest = (double)interestRate*getBalance();
	
	return interest;
} 
void SavingsAccount::display(ostream & os) const
{
	// your code
	
	os << "Account Type: Savings" << endl;
	os << "Balance: $ " << getBalance() << endl;
	os << "Interest Rate(%): " << interestRate*100.00 << endl;
}
