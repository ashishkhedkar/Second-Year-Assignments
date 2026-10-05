#include <iostream>
#include <cstring>
#include <string>
#define N 100
using namespace std;

class stack
{
public:
    char arr[N];
    string ex;
    int top;

    stack()
    {
        top = -1; // -1 indicates an empty stack
    }

    // Stack Operation: Push element onto top of stack
    void push(char c)
    {
        if (top == (N - 1))
        {
            cout << "stack overflow\n";
        }
        else
        {
            top += 1;
            arr[top] = c;
        }
    }

    // Stack Operation: Remove and return top element from stack
    char pop()
    {
        char c = ' ';
        if (top == -1)
        {
            // Stack underflow - stack is empty
            return ' ';
        }
        else
        {
            c = arr[top];
            top--;
        }
        return c;
    }

    // Utility: Return priority level of operators
    int precedence(char opr)
    {
        if (opr == '*' || opr == '/')
            return 2;
        if (opr == '+' || opr == '-')
            return 1;
        if (opr == '(')
            return 0; // Prevents '(' from being popped prematurely
        return -1;
    }

    char associativity(char opr)
    {
        if (opr == '*' || opr == '/' || opr == '+' || opr == '-')
            return 'L';
        else
            return 'R';
    }

    // Stack Operation: View top element without removing it
    char peek()
    {
        if (top == -1) return ' ';
        return arr[top];
    }

    string I2PConversion(string ex);
};

string stack::I2PConversion(string ex)
{
    int exp_length = ex.length(); // Length of the input infix expression
    int i = 0, j = 0;
    char op_exp[50];              // Output buffer for the postfix expression
    char topCh, temp;

    while (i < exp_length)
    {
        // 1. Process Operators (+, -, *, /)
        if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/')
        {
            if (top == -1)
            {
                push(ex[i]);
            }
            else
            {
                topCh = peek();
                // Pop operators with higher or equal precedence to output
                while (top != -1 && precedence(ex[i]) <= precedence(topCh))
                {
                    temp = pop();
                    op_exp[j++] = temp;
                    topCh = peek();
                }
                push(ex[i]); // Push current operator onto stack
            }
        }
        // 2. Process Opening Parenthesis
        else if (ex[i] == '(')
        {
            push(ex[i]);
        }
        // 3. Process Closing Parenthesis
        else if (ex[i] == ')')
        {
            temp = pop();
            // Pop elements to output until matching '(' is encountered
            while (top != -1 && temp != '(')
            {
                op_exp[j++] = temp;
                temp = pop();
            }
        }
        // 4. Process Operands (Letters / Digits)
        else
        {
            op_exp[j++] = ex[i];
        }
        i++;
    }

    // 5. Clear remaining operators from stack
    while (top != -1)
    {
        topCh = pop();
        if (topCh != '(' && topCh != ' ')
        {
            op_exp[j++] = topCh;
        }
    }

    op_exp[j] = '\0'; // Null-terminate postfix expression
    return op_exp;
}

int main()
{
    stack s;
    string ex;

    cout << "\nEnter an expression: ";
    cin >> ex;

    string op_exp = s.I2PConversion(ex);
    cout << "\nPostfix Expression is: " << op_exp << endl;

    return 0;
}
