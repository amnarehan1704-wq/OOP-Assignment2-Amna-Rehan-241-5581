#include <iostream>
using namespace std;

class Feature
{  
   public:
   	string name;
   	Feature(string n)
   	{
   		name=n;
	   }
	virtual void analyze()=0;//ek virtual function hai pure virtual iska matlab hai ke har derived class is function ka apna version banayegi.
	virtual ~Feature() {};//destructor ensure karta hai ke jab hum derived object delete karein toh memory properly free ho jaaye.
};
class LandFeature :public Feature
{
	public:
		LandFeature(string n):Feature(n){}
		void analyze()
		{
			cout<<"Land feature is detected:"<<name<<endl;
		}
};
class WaterFeature :public Feature
{
	public:
		WaterFeature(string n):Feature(n){}
		void analyze()
		{
			cout<<"Water feature is detected:"<<name<<endl;
		}
};
class Node
{
  public:
  int FeatureId;
  Feature *f;//pointer to Feature Land ha ya phir Water
  Node *next;
  Node(int id,Feature *feature)	
  {
  	FeatureId=id;
  	f=feature;
  	next=NULL;
  }
};
class SinglyLinkedList //Yeh class poori linked list ko manage karti hai.Iske paas head pointer hota hai list ka start point
{
	public:
		Node *head;
SinglyLinkedList()
{
	head=NULL;
}

void InsertAtEnd(int id,Feature *f)
{
	Node *newnode=new Node(id,f);
	if(head==NULL)
	{
		head=newnode;//Agar list empty hai, to naya node head ban jata hai.
		return;
	}
	Node *temp=head;
	while(temp->next!=NULL)//ka matlab ha agar agla node exist karta ha to age jao”                                                      
	{
		temp=temp->next;
	}
		temp->next=newnode;
  }

void deletebyId(int id)
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	if(head->FeatureId==id)
	{
		Node *temp=head;
		head=head->next;
		delete temp;
		return;
	}
	Node *curr=head;
	Node *prev=NULL;
while(curr!=NULL)
{
	if(curr->FeatureId==id)
	{
		break;
	}
prev=curr;
curr=curr->next;
	
}
if(curr==NULL)
{
	cout<<"Feature not found"<<endl;
	return;
}
prev->next=curr->next;
delete curr;
cout<<"Feature with "<<id<<" is deleted"<<endl;
}
void displayAll()
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
Node*temp=head;
while(temp!=NULL)//Loop tab tak chale jab tak temp NULL nahi hota
{
	cout<<temp->FeatureId<<")";
	Feature *feature=temp->f; //temp us node ke andar feature ko point  kar raha hume usko feature me save kara rahe 
	feature->analyze(); //then phir print karrahe ke land ya phir water
	temp=temp->next; //temp apne se  next wale node ke equal ho gaya 
}
}
  void reverseList() 
  {
    Node *prev=NULL;
    Node *curr=head;
    Node *next=NULL;

    while (curr!=NULL) 
	{
    next=curr->next;//store next node
    curr->next=prev;//reverse the pointer
    prev=curr;//move prev forward
    curr=next;//move curr forward
        }
        head=prev;//Loop ke baad prev pointer naya head ban jata hai
    }
};
int main() 
{
    SinglyLinkedList list;

    list.InsertAtEnd(1,new LandFeature("Forest"));
    list.InsertAtEnd(2,new WaterFeature("River"));
    list.InsertAtEnd(3,new LandFeature("Mountain"));
    list.InsertAtEnd(4,new WaterFeature("Lake"));
    list.InsertAtEnd(5,new LandFeature("Plateau"));
    list.InsertAtEnd(6,new WaterFeature("Sea"));

    cout<<"----------All Features---------"<<endl;
    list.displayAll();
    cout<<"-------------------------------"<<endl;

    cout<<"Deleting Feature ID 2"<<endl;
    list.deletebyId(2);
    list.displayAll();
    cout<<"-------------------------------"<<endl;

    cout<<"Reversing the List..."<<endl;
    list.reverseList();
    list.displayAll();
    cout<<"-------------------------------"<<endl;
    return 0;
}




