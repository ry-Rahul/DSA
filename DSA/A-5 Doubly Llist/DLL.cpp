#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
class Node
{
   public:
   int data;
   Node* nxt;
   Node* prev;
   
   Node(int val)
   {
   	data=val;
   	nxt=NULL;
   	prev=NULL;
	}
};
void dltAtHead(Node* &start)
{
	Node *t;
	t=start;
	t->prev=NULL;
	t->nxt=NULL;
	start=NULL;
	delete t;
}
void dltNode(Node* &start,int pos)
{
	
	if(pos==1)
	{
		dltAtHead(start);
		return;
	}
	Node *t,*n=NULL;
	t=start;
	int count=1;
	while(t!=NULL )
	{
		if(count==pos)
		  break;
		
		t=t->nxt;
		count++;
	}
	 
	     
	     
	if(t->nxt!=NULL)
	{
		t->nxt->prev=t->prev;
		t->prev->nxt=t->nxt;
	}
	 else{
	 	
		t->prev->nxt=NULL;
		t->prev=t->prev->prev;
	 }   

	delete t;
	
}
void insertAtHead(Node* &start,int data)
{
	Node *n=new Node(data);
	
	n->nxt=start;
	start->prev=n;
	start=n;
}
void insertAtTail(Node* &start,int data)
{
	Node *n=new Node(data);
	Node *temp=start;
	
	if(start==NULL)
	{
		n->prev=NULL;
		start=n;
		return;
	}
	while(temp->nxt!=NULL)
	{
		temp=temp->nxt;
	}
	temp->nxt=n;
	n->prev=temp;
	n->nxt=NULL;
}
void display(Node* start)
{
	Node *temp=start;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->nxt;
	}
	cout<<endl;
}
int main()
{
	system("color a");
	
	Node *start=NULL;
	insertAtTail(start,1);
	insertAtTail(start,2);
	insertAtTail(start,3);
	insertAtTail(start,4);
	insertAtTail(start,5);
	insertAtTail(start,6);
	insertAtTail(start,7);
	insertAtHead(start,8);
	
	display(start);
	
	//insertAtHead(start,7);
	dltNode(start,4);
	display(start);
	
	getch();
	return 0;
}