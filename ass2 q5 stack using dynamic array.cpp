#include <iostream>
using namespace std;

const int SIZE = 20; 
int stackArr[SIZE];  
int top = -1;     

void push(int value)
 {
    if (top == SIZE - 1) 
	{
        cout << "Stack Overflow! Cannot push " << value << endl;
    } 
	else
	 {
        top++;
        stackArr[top] = value;
    }
}

int pop() 
{
    if (top == -1) 
	{
        cout << "Stack Underflow!" << endl;
        return -1;
    } else {
        int val = stackArr[top];
        top--;
        return val;
    }
}

bool isEmpty()
 {
    return (top == -1);
}

void displayStack() 
{
    if (top == -1)
	 {
        cout << "Stack is empty" << endl;
    }
	 else
	  {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) 
		{
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}


void ChangeLocationIterative(char *Array, int b1, int b2) 
{
    top = -1;

    for (int i = b1; i <= b2; i++) 
	{
        push(Array[i]);
    }

    for (int i = b1; i <= b2; i++) 
	{
        Array[i] = pop();
    }
}

void PrintPatternIterative(int n) 
{
   
    top = -1;
    push(n);  

    cout << "Pattern:\n";

    while (!isEmpty()) 
	{
        int num = pop();

        for (int i = 0; i < num; i++) 
		{
            for (int j = 0; j <= i; j++)
			 {
                cout << "1 ";
            }
            cout << endl;
        }

        if (num > 1)
            push(num - 1);
    }
}

int main() {
    cout << "=== STACK OPERATIONS ===" << endl;
    push(10);
    push(20);
    push(30);
    displayStack();
    cout << pop() << " popped from stack" << endl;
    displayStack();

    cout << "\n=== Q1(a): ChangeLocation Using Stack ===" << endl;
    char arr[11] = {'P', 'R', 'O', 'G', 'R', 'A', 'M', 'M', 'I', 'N', 'G'};

    cout << "Original Array: ";
    for (int i = 0; i < 11; i++) cout << arr[i] << " ";
    cout << endl;

    ChangeLocationIterative(arr, 3, 7);

    cout << "After ChangeLocation: ";
    for (int i = 0; i < 11; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\n=== Q1(b): PrintPattern Using Stack ===" << endl;
    int n = 4;
    PrintPatternIterative(n);

    return 0;
}



