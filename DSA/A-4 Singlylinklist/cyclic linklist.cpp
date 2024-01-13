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
   
   Node(int val)
   {
   	data=val;
   	nxt=NULL;
	}
};
void removeCycle(Node* &start)
{
	Node *fast,*slow;
	fast=slow=start;
	do{
		slow=slow->nxt;
		fast=fast->nxt->nxt;
	}while(slow!=fast);  // slow->nxt!=fast->nxt;
	
	fast=start;
	
	while(fast->nxt!=slow->nxt)
	{
		fast=fast->nxt;
		slow=slow->nxt;
	}
	slow->nxt=NULL;
	
}
void makecyclic(Node* &start,int pos)
{
	Node *temp,*startnode;
	temp=start;
	int count=1;
	while(temp->nxt!=NULL)
	{
		if(pos==count)
		    startnode=temp;
		
		temp=temp->nxt;
		count++;
	}
	temp->nxt=startnode;
}
bool cycliclinklist(Node* &start)
{
	Node *fast,*slow;
	fast=slow=start;
	while(fast!=NULL && fast->nxt!=NULL)
	{
		slow=slow->nxt;
		fast=fast->nxt->nxt;
		if(fast==slow)
		    return true;
	}
	return false;
}
void display(Node* start)
{
	Node *t;
	t=start;
	while(t!=NULL)
	{
		cout<<t->data<<" -> ";
		t=t->nxt;
	}
	cout<<"NULL";
}
void inserAtTail(Node* &start,int val)
{
	Node *n=new Node(val);
	Node *t;
	t=start;
	if(t==NULL)
	{
		start=n;
		return;
	}
	while(t->nxt!=NULL)
	{
		t=t->nxt;
	}
	t->nxt=n;
	n->nxt=NULL;
	
}
int main()
{
	
	Node *start=NULL;
	inserAtTail(start,1);
	inserAtTail(start,2);
	inserAtTail(start,3);
	inserAtTail(start,4);
	inserAtTail(start,5);
	inserAtTail(start,6);
	
	//display(start);
	makecyclic(start,3);
	cout<<endl<<cycliclinklist(start)<<endl;
	removeCycle(start);
	cout<<endl<<cycliclinklist(start)<<endl;
	display(start);
	
	return 0;
}