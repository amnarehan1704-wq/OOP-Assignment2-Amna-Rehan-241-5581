#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char value) {
        data = value;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = NULL;
    }

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void ChangeLocationIterative(char *Array, int b1, int b2) {
    LinkedListStack stack;

    for (int i = b1; i <= b2; i++) {
        stack.push(Array[i]);
    }

    for (int i = b1; i <= b2; i++) {
        Array[i] = stack.pop();
    }
}
void PrintPatternIterative(int n) {
    LinkedListStack stack;


    for (int i = n; i >= 1; i--) {
        stack.push(i + '0');  
    }

    cout << "\nPattern:\n";
    int level = 1;
    while (!stack.isEmpty()) {
        int num = stack.pop() - '0';

        for (int i = 0; i < level; i++) {
            cout << "1 ";
        }

        if (num != n)
            cout << num;

        cout << endl;
        level++;
    }
}

int main() {
    cout << "=== LINKED LIST STACK DEMONSTRATION ===\n";
    LinkedListStack s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.display();
    cout << s.pop() << " popped from stack\n";
    s.display();

    cout << "\n=== Q1(a): ChangeLocation Using LinkedList Stack ===\n";
    char arr[11] = {'P','R','O','G','R','A','M','M','I','N','G'};

    cout << "Original Array: ";
    for (int i = 0; i < 11; i++) cout << arr[i] << " ";
    cout << endl;

    ChangeLocationIterative(arr, 3, 7);

    cout << "After ChangeLocation: ";
    for (int i = 0; i < 11; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\n=== Q1(b): PrintPattern Using LinkedList Stack ===\n";
    int n = 4;
    PrintPatternIterative(n);

    return 0;
}

