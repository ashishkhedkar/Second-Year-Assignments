#include <iostream>
#include <string>
using namespace std;

// Node represents a single task in the linked list
class Node {
public:
    string name;       
    int priority;      
    int time;        
    Node* next;        // Pointer to the next task

    // Constructor to initialize a task
    Node(string n, int p, int t) {
        name = n;
        priority = p;
        time = t;
        next = NULL;
    }
};

// TaskScheduler manages all the tasks
class TaskScheduler {
    Node* head;        // Points to the first task

public:
    // Constructor
    TaskScheduler() {
        head = NULL;
    }

    // Inserts a task according to its priority
    // Higher priority tasks are placed first
    void insertTask(string name, int priority, int time) {
        Node* newNode = new Node(name, priority, time);

        // If the list is empty or new task has higher priority,
        // insert it at the beginning
        if (head == NULL || priority > head->priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Find the correct position for the new task
        Node* temp = head;

        // Move forward while the next task has equal or higher priority
        while (temp->next != NULL &&
               temp->next->priority >= priority) {
            temp = temp->next;
        }

        // Insert the new task at the correct position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Displays all tasks in their scheduled order
    void display() {
        Node* temp = head;

        // Check if there are no tasks
        if (head == NULL) {
            cout << "No tasks available.\n";
            return;
        }

        cout << "\nTask Schedule:\n";

        // Traverse the linked list and display each task
        while (temp != NULL) {
            cout << "Task: " << temp->name
                 << " | Priority: " << temp->priority
                 << " | Time: " << temp->time << " min\n";

            temp = temp->next;
        }
    }

    // Executes tasks from highest to lowest priority
    void executeTasks() {
        // Check if there are no tasks
        if (head == NULL) {
            cout << "No tasks to execute.\n";
            return;
        }

        cout << "\nExecuting Tasks:\n";

        // Execute and remove tasks one by one
        while (head != NULL) {
            Node* temp = head;

            cout << "Executing: " << temp->name << endl;

            // Move head to the next task
            head = head->next;

            // Free memory of the completed task
            delete temp;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    int n;

    // Get the number of tasks from the user
    cout << "Enter number of tasks: ";
    cin >> n;

    // Input details for each task
    for (int i = 0; i < n; i++) {
        string name;
        int priority, time;

        cout << "\nEnter task name: ";
        cin >> name;

        cout << "Enter priority: ";
        cin >> priority;

        cout << "Enter execution time: ";
        cin >> time;

        // Add the task to the scheduler
        scheduler.insertTask(name, priority, time);
    }

    // Display tasks in priority order
    scheduler.display();

    // Execute all tasks
    scheduler.executeTasks();

    return 0;
}


