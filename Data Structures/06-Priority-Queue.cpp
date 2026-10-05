/*Arrival: Customers arrive at the coffee shop and stand in line. Order Processing: The first customer
in line gets their order taken, and the barista starts making the coffee.Serving: Once the first
customer is served, they leave the queue, and the next customer in line moves forward to be served.
Write a program to implement a simple queue*/ 

#include <iostream>
using namespace std;

#define MAX = 10
class Queue
{
	private:
	string Order[MAX];
	int f;
	int r;
	
	public:
	Queue() {
		f = -1;
		r = -1;
	}
	
	void enQueue (string Name) {
		if (r == MAX -1 ){
		cout << "Queue Overflowed, Kindly wait a few minutes while we process other orders :)" ;
		return;
	}
		if (r == -1){
			r = 0;
			f = 0;
			Order[r] = Name;
		}
		
		else { 
			r++;
			Order[r] = Name;
			}
			cout << "Order for << Name <<  added successfully!\n" ;
	}	
	
	void deQueue ()
	{
		if (f == -1) {
			f = -1;
			r = -1;
		}
		else { 
			f++;
		}
	}
	
	void display () {
		if (f == -1) {
			cout << "Queue is Empty! No Active Orders.\n" ;
			return;
		}
		
		cout << " --- Current Coffee Queue ---\n" ;
		for (int i = f; i <= r;, i++) {
			cout << (i - f + 1) << "." << Order[i] << "\n" ;
		}
	}
};

int main()
{
	Queue CoffeeShop;
	int choice;
	string customerName;
	
	while (choice != 4)
	{
		cout << "---------------------------------" ;
		cout << "	COFFEE SHOP MENU	\n" ;
		cout << "---------------------------------" ;
		cout << "\n1. Add Order\n2.Serve Order\n3.Display Current Orders\n4.Exit" ;
		cout << "1. Add New Order (enQueue)\n" ;
		cout << "2. Serve Next Order (deQueue)\n" ;
		cout << "3. Display all Orders\n" ;
		cout << "Exit" ;
		cout << "Enter your Choice: " ;
		cin >> choice;
			
	switch(choice) {
	case 1:
	cout << "Enter Customer \ Coffee Name: ";
	cin >> customerName;
	CoffeeShop.enQueue (customerName);
	cout << "Added!\n" ;
	break;
	
	case 2: 
	CoffeeShop.deQueue();
	cout << "Order Served!" ;
	break;
	
	case 3: 
	CoffeeShop.display();
	break;
	
	case 4: 
	cout << "Thank You, Glad to serve you!";
	break;
	
	default:
	cout << "Invalid Choice\n";
	break;
}
}

return 0;
}

	

	
