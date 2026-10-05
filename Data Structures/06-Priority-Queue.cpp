/*Arrival: Customers arrive at the coffee shop and stand in line. Order Processing: The first customer
in line gets their order taken, and the barista starts making the coffee.Serving: Once the first
customer is served, they leave the queue, and the next customer in line moves forward to be served.
Write a program to implement a simple queue*/ 

#include <iostream>
#include <string>
using namespace std;

#define MAX 10

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

    void enQueue(string Name) {
        if (r == MAX - 1) {
            cout << "Queue Overflowed! Kindly wait a few minutes while we process other orders.\n";
            return;
        }

        if (f == -1) {
            f = 0;
            r = 0;
        } else {
            r++;
        }

        Order[r] = Name;
        cout << "Order for " << Name << " added successfully!\n";
    }

    void deQueue() {
        if (f == -1) {
            cout << "Queue is empty! No active orders to serve.\n";
            return;
        }

        cout << "Order for " << Order[f] << " has been served!\n";

        if (f == r) {
            // Queue is now empty after serving the last customer
            f = -1;
            r = -1;
        } else {
            f++;
        }
    }

    void display() {
        if (f == -1) {
            cout << "Queue is empty! No active orders.\n";
            return;
        }

        cout << "\n--- Current Coffee Queue ---\n";
        for (int i = f; i <= r; i++) {
            cout << (i - f + 1) << ". " << Order[i] << "\n";
        }
    }
};

int main()
{
    Queue CoffeeShop;
    int choice = 0;
    string customerName;

    while (choice != 4)
    {
        cout << "\n---------------------------------\n";
        cout << "       COFFEE SHOP MENU          \n";
        cout << "---------------------------------\n";
        cout << "1. Add New Order (enQueue)\n";
        cout << "2. Serve Next Order (deQueue)\n";
        cout << "3. Display all Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer / Coffee Name: ";
                cin >> customerName;
                CoffeeShop.enQueue(customerName);
                break;

            case 2:
                CoffeeShop.deQueue();
                break;

            case 3:
                CoffeeShop.display();
                break;

            case 4:
                cout << "Thank you! Glad to serve you.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
