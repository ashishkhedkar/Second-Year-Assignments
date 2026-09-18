#include <iostream>
#include <string>
using namespace std;
// Base Class
class Staff
{
protected:
	int id;
	string name;
public:
	void acceptStaff()
	{
    	cout << "Enter Staff ID: ";
    	cin >> id;
    	cout << "Enter Name: ";
    	cin >> name;
	}
	void displayStaff()
	{
    	cout << "\nStaff ID  	: " << id;
    	cout << "\nName      	: " << name;
	}
};
// Derived Class
class Teaching : public Staff
{
private:
	string department;
	int experience;
public:
	void accept()
	{
    	acceptStaff();
    	cout << "Enter Department: ";
    	cin >> department;
    	cout << "Enter Experience (years): ";
    	cin >> experience;
	}
	void display()
	{
    	displayStaff();
    	cout << "\nDepartment	: " << department;
    	cout << "\nExperience	: " << experience << " years\n";
	}
};
int main()
{
	int n, choice;
	cout << "Enter number of Teaching Staff: ";
	cin >> n;
	Teaching obj[n];
	do
	{
    	cout << "\n\n******** MENU ********";
    	cout << "\n1. Accept Teaching Staff Details";
    	cout << "\n2. Display Teaching Staff Details";
    	cout << "\n3. Exit";
    	cout << "\nEnter your choice: ";
    	cin >> choice;
    	switch (choice)
    	{
    	case 1:
        	cout << "\nEnter Teaching Staff Details:\n";
        	for (int i = 0; i < n; i++)
        	{
            	cout << "\nEnter details of Teaching Staff " << i + 1 << endl;
            	obj[i].accept();
        	}
        	break;
    	case 2:
        	cout << "\n===== Teaching Staff Database =====\n";
        	for (int i = 0; i < n; i++)
        	{
            	cout << "\nTeaching Staff " << i + 1 << endl;
            	obj[i].display();
        	}
        	break;
    	case 3:
        	cout << "\nExiting Program...";
        	break;

    	default:
        	cout << "\nInvalid Choice! Please try again.";
    	}

	} while (choice != 3);
	return 0;
}


