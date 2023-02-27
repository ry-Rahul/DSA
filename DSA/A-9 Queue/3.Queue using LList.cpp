#include<iostream>    //Queue  using Linked List:
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;  
class Queue
{
	private:
		struct node
		{
			int item;
			node *nxt;
		};
	    node *front,*rear;
	public:
		
		Queue()
		{ front=NULL; rear=NULL; }
		
		void insertData(int data);
		void dltData();
		void viewData();
};
void Queue::dltData()
{
	if(front==NULL && rear==NULL)
	    cout<<"Queue underflow:"<<endl;
	else
	{
		if(front==rear)
            {
            	front=NULL;
            	rear=NULL;
			}
			else
			{
				node *t;
				t=front;
				front=t->nxt;
				delete t;
			}
	}
}
void Queue::viewData()
{
	node *t;
	t=front;
	while(t)
	{
		cout<<t->item<<" ";
		t=t->nxt;
	}
}
void Queue::insertData(int data)
{
	node *n=new node;
	n->item=data;
	n->nxt=NULL;
	if(front==NULL && rear==NULL)
	{
		front=n;
		rear=n;
	}
	else
	{
		rear->nxt=n;
		rear=n;
	}
}

int main()
{
	system("color b");
	Queue q1;
	
	q1.insertData(10);
	q1.insertData(20);
	q1.insertData(30);
	q1.dltData();
	q1.dltData();
	q1.dltData();
	q1.dltData();
	q1.viewData();
	
	getch();
}