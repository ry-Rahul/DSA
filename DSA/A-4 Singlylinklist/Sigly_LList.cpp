#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
class linklist
{
	private:
	struct Node
    {
	    int item;
	    Node *nxt;
	    //Node *prev;
    };
    struct Node *start;
    
    public:
       linklist()
       {
       	   start=NULL;
	   }
	//void InputatFirst(int data);
	void InputatLast(int data);
	void InputatFirst(int data);
	void InputatMid(int data,int value);
	void Viewlist();
	void DltFirst();
	void DltMid(int value);
	void DltLast();
	void reverseLlist();
	
	//void reverserecursive();
};
//void linklist::reverserecursive()
//{
//	if(start==NULL || start->nxt==NULL)
//	{
//		start==NULL;
//	}
//	Node *n=reverserecursive(start->nxt);
//	start->nxt->nxt=start;
//	start->nxt=NULL;
//}
void linklist::reverseLlist()
{
	Node *t1,*t2,*t3;
	t1=NULL;
	t2=start;
	while(t2!=NULL)
	{
		t3=t2->nxt;
		t2->nxt=t1;
		
		t1=t2;
		t2=t3;
	}
	start=t1;
}

void linklist::DltMid(int value)
{
	Node *t1,*t2;
	  t2=NULL;
	  t1=start;
	while(t1)
	{
		t2=t1;
		if(t1->item==value)
		   break;
		t1=t1->nxt;
	}
	if(t1==NULL)
	cout<<"No item with value "<<value<<" in the list"<<endl;
	else
	{
		if(t2==NULL)
		   start=NULL;
		else
		   t2->nxt=t1->nxt;
		delete t1;
	}
	
}
void linklist::DltFirst()
{
	Node *t;
	 t=start;
	 start=t->nxt;
	 delete t;
}
void linklist::Viewlist()
{
	Node *n;
	n=start;
	while(n)
	{
		cout<<n->item<<"->";
		n=n->nxt;
	}
	cout<<"NULL"<<endl;

}
void linklist::DltLast()
{
	Node *t1,*t2;
	t2=NULL;
	if(start==NULL)
        cout<<"List is empty:"<<endl;
    else
    {
    	t1=start;
    	while(t1->nxt!=NULL)
    	{
    		t2=t1;
    		t1=t1->nxt;
		}
		if(t2==NULL)
	       start=NULL;
	    else
		t2->nxt=NULL;
		delete t1;
	}
}
void linklist::InputatMid(int data,int value)
{
	Node *t,*n;
	t=start;
	while(t)
	{
		if(t->item==value)
		  break;
		t=t->nxt;
	}
	if(t!=NULL)
	{
		n=new Node;
		n->item=data;
		n->nxt=t->nxt;
		t->nxt=n;
	}
	else
	cout<<"No item with value "<<value<<" in the list"<<endl;
	
	
}
void linklist::InputatFirst(int data)
{
	Node *n=new Node;
	n->item=data;
	if(start==NULL)
	{
	   n->nxt=NULL;
	   start=n;
    }
	else
	{
		n->nxt=start;
		start=n;
	 } 
}
void linklist::InputatLast(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->nxt=NULL;
	
	if(start==NULL)
	{
		start=ptr;
	}
	else
	   {
	      Node *temp;
		  temp=start;
		  while(temp->nxt!=NULL)
		    temp=temp->nxt;
		    temp->nxt=ptr;
		}
}
int main()
{
	system("color a");
	system("cls");
	
	linklist l1;
	l1.InputatFirst(50);
	l1.InputatLast(10);
	//l1.InputatMid(12,10);
	//l1.InputatMid(98,50);
    l1.InputatFirst(100);
    l1.InputatLast(98);
    l1.InputatFirst(11);
    l1.InputatFirst(121);
	l1.Viewlist();
	
	//l1.reverseLlist();
	//l1.Viewlist();
	
	getch();
}