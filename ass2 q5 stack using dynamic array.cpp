#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

const int SIZE=5; 
int stack[SIZE];  
int top=-1;     

void push(int value) 
{
    if(top==SIZE-1) 
	{
        cout<<"Stack Overflow! Cannot push"<<value<<endl;
    }
	 else 
	{
        top++;
        stack[top]=value;
        cout<<value<<"pushed into stack"<<endl;
    
    }
}
void pop() 
{
    if(top==-1)
	{
       cout<<"Stack Underflow! Nothing to pop"<<endl;
  } 
  else
   {
       cout<<stack[top]<<" popped from stack"<<endl;
       top--;
   }
}

 
void peek() 
{
   if(top==-1)
       cout<<"Stack is empty"<<endl;
   else
        cout<<"Top element: "<<stack[top]<<endl;
}

bool isEmpty()
{
    return(top==-1);
}
void display() 
{
    if(top==-1)
	 {
        cout<<"Stack is empty"<<endl;
    }
	 else
	  {
       cout<<"Stack elements";
       for (int i=top;i>=0;i--) 
	   {
           cout<<stack[i]<<" ";
       }
        cout<<endl;
    }
}
int main() {
   push(10);
   push(20);
   push(30);
   display();
   pop();
    display();
    peek();
  if(isEmpty())
       cout<<"Stack is empty now"<<endl;
  else
       cout<<"Stack is not empty"<<endl;

    return 0;

}
