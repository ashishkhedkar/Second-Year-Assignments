#include <iostream>
#include <string>

using namespace std;

class Employee
{
	private:
	string Name;
	string EmployeeID;
	string Department, DoJ, Departmemt, Address, Phone;
    
	static int EmployeeCount;   // Shared across all instances of the Employee class
    
	public:
	Employee ()            	// Default Constructor
	{
    	Name = "NA";
    	EmployeeID = "NA";
    	Department = "NA";
    	DoJ = "NA";
    	Address = "NA";
    	Phone = "NA";
    	EmployeeCount ++;
	}
    
	Employee (string n, int ID, string Dept, string doj, string add, string phn)  // Parameterized Constructor
	{
    	Name = n;
    	EmployeeID = ID;
    	Department = Dept;
    	DoJ = doj;
    	Address = add;
    	Phone = phn;
    	EmployeeCount ++;
	}
    
	Employee (const Employee &e)  	// Copy Constructor implemented using Pass by Reference
	{
    	Name = e.Name;
    	EmployeeID = e.EmployeeID;
    	Department = e.Department;
    	DoJ = e.DoJ;
    	Address = e.Address;
    	Phone = e.Phone;
    	EmployeeCount ++;
	}
    
    
	~ Employee ()	// Destructor to the Constructor
	{
    	EmployeeCount --;
	}
    
	void display () 	// Member Function to Display Stuff
	{
    	cout << "\n----------------------------------------" << endl;
    	cout << "Employee Name: " << Name << endl;
    	cout << "Employee ID: " << EmployeeID << endl;
    	cout << "Department: " << Department << endl;
    	cout << "Date of Joining: " << DoJ << endl;
    	cout << "Employee Contact Address: " << Address << endl;
    	cout << "Employee Contact No.: " << Phone << endl;
    	cout << "\n----------------------------------------" << endl;
	}
    
	static void showEmployeeCount ()      	// Static Member Function for the Static Data Member
	{
    	cout << "Total Active Objects: " << EmployeeCount << endl;
	}
};

int Employee :: EmployeeCount = 0;	// Initialize static member variable outside the class

int main ()
{
	string Name, Department, DoJ, Address, Phone;
	int ID;
    
	cout << "Enter Employee's Name: ";
	cin >> Name;
	cout << "Enter Employee's ID: ";
	cin >> ID;
	cout << "Enter Employee's Dept: ";
	cin >> Department;
	cout << "Enter Employee's Date of Joining: ";
	cin >> DoJ;
	cout << "Enter Employee's Contact Address: ";
	cin >> Address;
	cout << "Enter Employee's Contact No.: ";
	cin >> Phone;
    
	// Creating object using Parameterized Constructor
	Employee E (Name, ID, Department, DoJ, Address, Phone);    
	cout << "\nEmployee's Entered Information: ";
	E.display ();
    
	// Creating object dynamically using Heap Allocation
	Employee *p = new Employee ("XYZ", 0000, "ABC", "15/11/2026", "xyz@work.com", "9876598765");
	cout << "\nDynamically allocated Employee: ";
	p -> display ();
    
	// Creating object using Copy Constructor
	Employee copyEmployee (E);
	cout << "\nCopied Employee: ";
	copyEmployee.display ();
    
	Employee :: showEmployeeCount ();
    
	delete p;   // Calling the Destructor
    
	cout << "\nAfter Deleting Dynamic Object, ";
	Employee :: showEmployeeCount ();
    
	return 0;
    
}

