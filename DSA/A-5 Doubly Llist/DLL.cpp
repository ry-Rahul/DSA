#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
class node
{
   public:
   int data;
   node* nxt;
   node* prev;
   
   node(int val)
   {
   	data=val;
   	nxt=NULL;
   	prev=NULL;
	}
};
void dltAtHead(node* &start)
{
	node *t;
	t=start;
	t->prev=NULL;
	t->nxt=NULL;
	start=NULL;
	delete t;
}
void dltNode(node* &start,int pos)
{
	
	if(pos==1)
	{
		dltAtHead(start);
		return;
	}
	node *t,*n=NULL;
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
void insertAtHead(node* &start,int data)
{
	node *n=new node(data);
	
	n->nxt=start;
	start->prev=n;
	start=n;
}
void insertAtTail(node* &start,int data)
{
	node *n=new node(data);
	node *temp=start;
	
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
void display(node* start)
{
	node *temp=start;
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
	
	node *start=NULL;
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