#include <iostream>
using namespace std;
const int SIZE=5; 

class Customer 
{
public:
	int id;
    string name;
    int tickets;
    
};
class Queue 
{
private:
    Customer arr[SIZE];
    int front;
    int rear;

public:
  Queue() 
  {
    front=-1;
    rear=-1;
    }
bool isEmpty() 
{
    return(front== -1 || front>rear);
    }
bool isFull() 
{
   return(rear==SIZE-1);
    }
void enqueue(int id,string name,int tickets) 
{
  if (isFull())
   {
    cout<<"Queue is full! Cannot add "<<name<<endl;
    return;
        }

  if (front==-1)
     front=0;

        rear++;
        arr[rear].id=id;
        arr[rear].name=name;
        arr[rear].tickets=tickets;

        cout<<name<<" added to the queue"<<endl;
    }
void dequeue()
 {
   if (isEmpty())
  {
    cout<<"Queue is empty! No customer to serve"<<endl;
    return;
        }

    cout<<"Serving customer:"<<arr[front].name<<endl;
    front++;

    if (front > rear) 
	{ 
            front=rear=-1;//agar que empty ho
        }
    }
void display() 
  {
    if (isEmpty()) 
	{
      cout<<"No customers in queue"<<endl;
       return;
        }
    cout << "Current Queue:"<<endl;
    for (int i=front;i<=rear;i++) 
	{
            cout<<"ID:"<<arr[i].id<<", Name:"<<arr[i].name<<", Tickets:"<<arr[i].tickets<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;

    q.enqueue(1,"Amna",2);
    q.enqueue(2,"Sara",3);
    q.enqueue(3,"Maryam",1);

    q.display();

    q.dequeue();
    q.display();

    q.enqueue(4, "Fatima", 4);
    q.display();

    return 0;
}

    

