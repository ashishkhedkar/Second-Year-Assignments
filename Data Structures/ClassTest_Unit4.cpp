// Implementing a stack using a struct array in C++ with O(1) time complexity and O(N) space complexity

#include <iostream>
using namespace std;

// Structure to represent a stack
struct Stack {
    int top;         // Index of the top element
    int capacity;    // Maximum size of the stack
    int* arr;        // Pointer to the array storing elements
};

// Function to insert an element into the stack
void push(Stack* s, int value) {
    // Check if the stack is full
    if (s->top == s->capacity - 1) {
        cout << "Stack Overflow!\n";
        return;
    }

    s->arr[++s->top] = value;  // Increment top and insert element
    cout << value << " pushed into stack.\n";
}

// Function to remove the top element from the stack
int pop(Stack* s) {
    // Check if the stack is empty
    if (s->top == -1) {
        cout << "Stack Underflow!\n";
        return -1;
    }

    return s->arr[s->top--];  // Return element and decrement top
}

// Function to view the top element without removing it
int peek(Stack* s) {
    // Check if the stack is empty
    if (s->top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }

    return s->arr[s->top];  // Return the top element
}

// Function to display all stack elements
void display(Stack* s) {
    // Check if the stack is empty
    if (s->top == -1) {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Stack elements (top to bottom): ";

    // Traverse the stack from top to bottom
    for (int i = s->top; i >= 0; i--) {
        cout << s->arr[i] << " ";
    }

    cout << "\n";
}

int main() {
    Stack s;
    int arr[100];          // Array to store stack elements
    int choice, value;

    // Initialize the stack
    s.top = -1;            // -1 indicates an empty stack
    s.capacity = 100;      // Set maximum capacity to 100
    s.arr = arr;           // Assign the array to the stack

    do {
        cout << "\n--- STACK OPERATIONS ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(&s, value);
                break;

            case 2:
                value = pop(&s);
                if (value != -1)
                    cout << "Popped element: " << value << "\n";
                break;

            case 3:
                value = peek(&s);
                if (value != -1)
                    cout << "Top element: " << value << "\n";
                break;

            case 4:
                display(&s);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;  
