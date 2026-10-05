
#include <iostream>
#include <string>

using namespace std;

void checkParantheses (string expr)
{
	char stack[100];                   // Character Array for Stack
	int top = -1;                      // Stack is Empty
	int i;
	
	for (i = 0; i < expr.length(); i++)
	{
		char ch = expr[i];
		
		// 1. PUSH opening brackets onto the stack
		if (ch == '(' || ch == '{' || ch == '[')
		{
			top ++;            // PUSH operation
			stack[top] = ch;
		}
		
		// 2. Check if closing brackets are present
		else if (ch ==')' || ch == '}' || ch == ']')
		{
			/* 2 conditons here, 
			 * 1: Missing opening bracket
			 * 2: Mismatch b/w opening and closing bracket
			 */
				 // if stack is empty, opening bracket is missing
				if (top == -1)
				{
					cout << "Invalid: Missing opening bracket for '" << ch << "'" << endl;
					return;
				}
				
				// check if the brackets match, if yes then pop them from stack
				char topCh = stack[top];
				if ((topCh == '(' && ch == ')') || (topCh == '{' && ch == '}') || (topCh == '[' && ch == ']'))
				{
				top --; 		// POP operation
				}
			
			// condition for mismatch of brackets
			else
			{
				cout << "Invalid: Mismatched bracket.\nExpected closing for '" << topCh << "' but got '" << ch << "'" <<endl;
				return;
			}
		}
	}
	
	// outside for loop
	
	// 3. Final Checks, Valid, Invalid
	if (top == -1) 
	{
	cout << "Valid: All parantheses are balanced." << endl;
	}
	
	else
	{
	cout << "Invalid: Missing a valid closing bracket." << endl; 
	}
	
}

int main ()
{
	string expression;
	
	cout << "Enter Expression: ";
	cin >> expression;
	
	checkParantheses(expression);
	
	return 0;
}

		
	
