#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    string account_type;
    int account_number;
    float balance;

public:
    void info() {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter account type: ";
        cin >> account_type;

        cout << "Enter account number: ";
        cin >> account_number;

        cout << "Enter balance: ";
        cin >> balance;
    }

    void display() {
        cout << "\nAccount Details" << endl;
        cout << "Name: " << name << endl;
        cout << "Account type: " << account_type << endl;
        cout << "Account number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit() {
        float amount;

        cout << "Enter amount to deposit: ";
        cin >> amount;

        try {
            if (amount <= 0)
                throw amount;

            balance += amount;

            cout << "Deposited amount is: " << amount << endl;
            cout << "Total balance: " << balance << endl;
        }
        catch (float) {
            cout << "Invalid amount" << endl;
        }
    }

    void withdraw() {
        float amount;

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        try {
            if (amount <= 0)
                throw amount;

            if (amount > balance)
                throw "Insufficient balance";

            balance -= amount;

            cout << "Withdrawn amount is: " << amount << endl;
            cout << "Withdrawal successful" << endl;
            cout << "Total balance: " << balance << endl;
        }
        catch (float) {
            cout << "Invalid amount" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};

int main() {
    BankAccount b1;
    b1.info();

    int choice;

    while (true) {
        cout << "\n===== BANK MENU =====" << endl;
        cout << "1. Display account details" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice < 1 || choice > 4)
                throw choice;

            switch (choice) {
                case 1:
                    b1.display();
                    break;

                case 2:
                    b1.deposit();
                    break;

                case 3:
                    b1.withdraw();
                    break;

                case 4:
                    cout << "Thank you for using the banking system"
                         << endl;
                    return 0;
            }
        }
        catch (int) {
            cout << "Invalid choice! Please try again" << endl;
        }
    }

    return 0;

}

