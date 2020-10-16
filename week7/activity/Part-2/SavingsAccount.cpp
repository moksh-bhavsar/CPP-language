#include "SavingsAccount.h"

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ): Account( initialBalance ) 
{
	// your code
	interestRate = rate;
}

double SavingsAccount::calculateInterest() {
	// your code
	double interest = getBalance()*interestRate;
	return interest;
} 
void SavingsAccount::display(ostream & os) const
{
	// your code
	os.precision(2);
	os << fixed;
	os << "Account type: Saving" << endl;
	os << "Balance: $ " << getBalance() << endl;
	os << "Interest Rate (%): " << interestRate*100 << endl;
}
