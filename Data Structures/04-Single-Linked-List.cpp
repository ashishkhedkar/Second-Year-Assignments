


#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int task_ID;
    string task_name;
    int priority;
    int exe_time;
    Node* next;

    // Default constructor
    Node() {
        task_ID = 0;
        task_name = "";
        priority = 0;
        exe_time = 0;
        next = NULL;
    }

    // Parameterized constructor
    Node(int ID, string name, int p, int time) {
        task_ID = ID;
        task_name = name;
        priority = p;
        exe_time = time;
        next = NULL;
    }
};

class Tasks {
public:
    Node* head;   // Pointer to dummy header node
    Node* temp;   // Temporary pointer for traversal

    Tasks() {
        // Create an empty dummy header node
        head = new Node();
        temp = NULL;
    }

    // Insert a task according to priority
    void insertTask() {
        int id, p, time;
        string name;

        cout << "\nEnter Task ID: ";
        cin >> id;

        cout << "Enter Task Name: ";
        cin >> name;

        cout << "Enter Priority: ";
        cin >> p;

        cout << "Enter Execution Time: ";
        cin >> time;

        // Create the new task node
        Node* t = new Node(id, name, p, time);

        // Start from the header
        Node* prev = head;
        Node* curr = head->next;

        // Find the correct position.
        // Higher priority tasks are placed first.
        while (curr != NULL && curr->priority >= t->priority) {
            prev = curr;
            curr = curr->next;
        }

        // Insert the new node between prev and curr
        t->next = curr;
        prev->next = t;

        cout << "\nTask added successfully!\n";
    }

    // Display all tasks
    void displayTask() {
        temp = head->next;

        if (temp == NULL) {
            cout << "\nNo tasks available.\n";
            return;
        }

        cout << "\n========== Scheduled Tasks ==========\n";

        while (temp != NULL) {
            cout << "Task ID       : " << temp->task_ID << endl;
            cout << "Task Name     : " << temp->task_name << endl;
            cout << "Priority      : " << temp->priority << endl;
            cout << "Execution Time: " << temp->exe_time << " mins" << endl;
            cout << "-------------------------------------\n";

            temp = temp->next;
        }
    }
};

int main() {
    Tasks taskObj;
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "      TASK SCHEDULER MENU      \n";
        cout << "===============================\n";
        cout << "1. Insert Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            taskObj.insertTask();
            break;

        case 2:
            taskObj.displayTask();
            break;

        case 3:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
