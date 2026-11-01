
#include <iostream>
#include <fstream>

using namespace std;

class Inventory {
    
	string itemName;
	string itemID;
	double price;
	int quantity;
    
	public:
	void inputData ();
	void displayData ();
    
};

void Inventory :: inputData () {
    
	cout << "\n--- Enter Item Details --- " << endl;
	cout << "What is the Item?  ->  ";
	cin >> itemName;
	cout << "What is the Item ID?  ->  ";
	cin >> itemID;
	cout << "What is the Price of the Item (in Indian Ruppees)?  ->  ";
	cin >> price;
	cout << "What is the Net Quantity of the Item?  ->  ";
	cin >> quantity;
}

void Inventory :: displayData () {
    
	cout << "\n --- Details --- " << endl;
	cout << "Item: " << itemName << " (" << itemID << ")";
	cout << "\nPrice (INR): " << price;
	cout << "\nNet Quantity: " << quantity;
	cout << "\nTotal Price: " << (price * quantity);
}

int main ()
{
	Inventory I;
	I.inputData();
    
	ofstream ofFileObj;
    
	ofFileObj.open ("input.txt", ios::out);
	ofFileObj.write((char*)&I, sizeof(I));
	ofFileObj.close ();
    
	ifstream ifFileObj;
    
	ifFileObj.open ("input.txt", ios::in);
	ifFileObj.read((char*)&I, sizeof(I));
	ifFileObj.close ();
    
	I.displayData ();
    
	return 0;
}

