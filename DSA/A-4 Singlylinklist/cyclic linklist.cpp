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
   
   node(int val)
   {
   	data=val;
   	nxt=NULL;
	}
};
void removeCycle(node* &start)
{
	node *fast,*slow;
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
void makecyclic(node* &start,int pos)
{
	node *temp,*startnode;
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
bool cycliclinklist(node* &start)
{
	node *fast,*slow;
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
void display(node* start)
{
	node *t;
	t=start;
	while(t!=NULL)
	{
		cout<<t->data<<" -> ";
		t=t->nxt;
	}
	cout<<"NULL";
}
void inserAtTail(node* &start,int val)
{
	node *n=new node(val);
	node *t;
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
	
	node *start=NULL;
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