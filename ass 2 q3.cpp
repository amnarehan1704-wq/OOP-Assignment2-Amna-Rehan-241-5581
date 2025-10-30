#include <iostream>
using namespace std;

class Node
{
	public:
		int Bookid;
		string Title;
		string Author;
		Node *next;
		Node *prev;
Node(int id,string t,string a)
{   
    Bookid=id;
    Title=t;
    Author=a;
    next=NULL;
    prev=NULL;
          }
};
class DoublyLinkedList
{ 
   public:
	Node *head=NULL;
	Node *tail=NULL;

void AddAtBeginning(int id,string title,string author) 
{
    Node* newNode=new Node(id,title,author);
    if(head==NULL) 
	{
         head=tail=newNode;
     } 
	else 
	{
     newNode->next = head;
     head->prev = newNode;
     head = newNode;
        }
    
    }

void AddAtEnd(int id,string title,string author)
 {
   Node* newNode=new Node(id,title,author);
    if(tail==NULL) 
	{
        head=tail=newNode;
      }
	else 
	{
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
        }
    
    }
void addAtPosition(int pos,int id,string title,string author)
{
  if(pos<=1 || head==NULL)
  {
    AddAtBeginning(id,title,author);
    return;
    }

    Node* temp=head;
    int count=1;
    
    while(temp->next!= NULL && count<pos-1) 
  {
    temp=temp->next;
     count++;
    }

    if(temp->next==NULL)
    {
       AddAtEnd(id,title,author);
       return;
    }

    Node* newNode=new Node(id,title,author);

    Node* nextNode=temp->next; 

    newNode->next=nextNode;
    newNode->prev=temp;

    nextNode->prev=newNode;
    temp->next=newNode;
}
void deleteByID(int id)
 {
    if(head==NULL)
  {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=head;

    while(temp!=NULL) {
        if(temp->Bookid==id) 
		{
            break;
        }
        temp=temp->next;
    }

    if(temp==NULL) 
 {
        cout<<"Book ID "<<id<<"not found"<<endl;
        return;
    }

    if(temp==head) 
 {
    head=head->next;
        if(head!=NULL)
		 {
            head->prev=NULL;
        }
		 else 
		 {
            tail=NULL; 
        }
    }

    else if(temp==tail) 
	{
        tail=tail->prev;
        tail->next=NULL;
    }

    else
	 {
        Node* prevNode=temp->prev;  
        Node* nextNode=temp->next;   

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    delete temp;
}
void displayForward() 
{
    if(head==NULL) 
	{
      cout<<"Library is empty"<<endl;;
       return;
        }

        Node* temp=head;
        while(temp!=NULL) 
		{
            cout<<"ID: "<<temp->Bookid
            << " , Title: " <<temp->Title
            << " , Author: "<<temp->Author<<endl;
            temp=temp->next;
        }
    }

void displayBackward()
{
   if(tail==NULL) 
{
    cout<<"Library is empty"<<endl;
    return;
    }

    cout<<"Books in reverse order"<<endl;

    Node* temp=tail; 

    while (temp != NULL) {
        cout<<"ID: "<<temp->Bookid
        <<" , Title: "<<temp->Title
        <<" , Author: "<<temp->Author<<endl;

        temp = temp->prev; 
    }
}
};
int main() {
    DoublyLinkedList library;
    
    library.AddAtBeginning(101,"The Reluctant Fundamentalist","Mohsin Hamid");
    library.AddAtEnd(102,"Moth Smoke","Mohsin Hamid");
    library.AddAtEnd(103,"A Case of Exploding Mangoes","Mohammad Hanif");
    library.addAtPosition(2,104,"Songs of Blood and Sword","Fatima Bhutto");

    library.displayForward();
     library.displayBackward();


    cout << "Deleting book with ID 102"<<endl;
    library.deleteByID(102);
  
    cout<<"After deletion the list is:"<<endl;
    library.displayForward();
    library.displayBackward();

    return 0;
}





    
