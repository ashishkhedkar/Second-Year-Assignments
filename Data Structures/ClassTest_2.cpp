// Implementing a stack using a struct array in C++ with O(1) time complexity and O(N) space complexity

#include <iostream>
using namespace std;

// Struct definition for the Stack
struct Stack {
    int top;         // Pointer/Index to the top element
    int capacity;    // Maximum capacity of the stack
    int* arr;        // Array to store stack elements
};

// Initialize the stack with a given capacity
Stack* createStack(int capacity) {
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = new int[capacity];
    return stack;
}

// Push operation - Time Complexity: O(1)
void push(Stack* stack, int value) {
    // Direct check for Stack Overflow
    if (stack->top == stack->capacity - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    stack->arr[++stack->top] = value;
    cout << "Pushed: " << value << "\n";
}

// Pop operation - Time Complexity: O(1)
int pop(Stack* stack) {
    // Direct check for Stack Underflow
    if (stack->top == -1) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek/Top operation - Time Complexity: O(1)
int peek(Stack* stack) {
    // Direct check for Empty Stack
    if (stack->top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack* stack = createStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "Top element is: " << peek(stack) << "\n";

    cout << "Popped: " << pop(stack) << "\n";
    cout << "Popped: " << pop(stack) << "\n";

    cout << "Top element is now: " << peek(stack) << "\n";

    // Clean up memory
    delete[] stack->arr;
    delete stack;

    return 0;
}
