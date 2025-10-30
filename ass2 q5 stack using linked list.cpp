#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) 
{
        data=value;
        next=NULL;
    }
};

class LinkedList 
{
private:
    Node* top; 
public:
    LinkedList() 
		{
        top=NULL;
    }

    void push(int value) 
	{
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
        cout<<value<<" pushed to stack"<<endl;
    }

    void pop() 
	`{
        if(top==NULL)
		{
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<top->data<<"popped from stack"<<endl;
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    void peek() 
	{
        if(top==NULL) 
		{
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Top element: "<<top->data<<endl;
    }

    void display() {
        if(top==NULL) 
    {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Stack elements(top to bottom): ";
        Node* temp=top;
        while(temp!=NULL) 
		{
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.peek();
    s.display();

    return 0;
}
