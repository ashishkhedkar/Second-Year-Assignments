// Implement a class to illustrate working of a bank account of a customer that consists of the following members.


#include <iostream>
using namespace std;

class BankAccount
{
	string Name;
	string AccType;
	long int AccNum;
	float AccBalance;
    
	public:
	void Accept()
	{
    	cout << "Please Enter your details:" << endl;
    	cout << "Name: ";
    	cin >> Name;
    	cout << "Account Type (Savings / Current): ";
    	cin >> AccType;
    	cout << "Account Number: ";
    	cin >> AccNum;
    	cout << "Current Account Balance: ";
    	cin >> AccBalance;
	}
    
	void Deposit()
	{

    	float amountD;
    	cout << "Amount to be deposited: ";
    	cin >> amountD;
 
   	AccBalance = AccBalance + amountD;
    	cout << "\nAmount Deposited\nUpdated Account Balance is: " << AccBalance << endl;
	}
    
	void Withdraw()
	{
    	float amountW;
    	cout << "\nEnter the amount to be withdrawn: ";
    	cin >> amountW;
    	AccBalance = AccBalance - amountW;
    	cout << "\nAmount Withdrawn\nUpdated Bank Balance: " << AccBalance << endl;
	}
    
 	void Display()
	{
    	cout << "Name: " << Name << endl;
    	cout << "Account Type: " << AccType << endl;
    	cout << "Account Number: " << AccNum << endl;
    	cout << "Balance: " << AccBalance << endl;
	}
};

int main()
{
	BankAccount b;
	b.Accept();
    
	int loop;
    
	while (loop != 3)
	{
    	cout << "\nHello!\nChoose from the following options: \n1. Deposit\n2. Withdraw\n3. Display\n4. Exit" << endl;
    	cin >> loop;
   	 
     	switch (loop)
    	{
        	case 1:
        	b.Deposit();
        	break;
   	 
        	case 2:
        	b.Withdraw();
        	break;
   	 
        	case 3:
        	b.Display();
        	break;
       	 
        	case 4:
        
	cout << "\nThank You!";

        	break;
   	 
        	default:
        	cout << "Kindly select from the given options.";
        	break;
    	}
	}
    
	return 0;
    
}

