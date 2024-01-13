#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
class DLL
{
	private:
	struct node
    {
	    int item;
	    node *nxt;
	    node *prev;
    };
    struct node *start;
    
    public:
       DLL()
       {
       	   start=NULL;
	   }
	void ViewList();
	void inputAtFirst(int data);
	void inputAtLast(int data);
	void inputAtMid(int value,int data);
	void dltAtFirst();
	void dltAtLast();
	void dltatAtMid(int value);
};
void DLL::dltatAtMid(int value)
{
	node *t1,*t2;
	t2=NULL;
	t1=start;
		while(t1)
	      {
		     if(t1->item==value)
		        break;
	      	 t2=t1;
		     t1=t1->nxt;
	      }
	    if(t1==NULL)
	       cout<<"No item with value in the list:"<<endl;
	    else
	    {
	    	if(t1->nxt==NULL)
	    	{
	    		t1->prev=NULL;
	    		t2->nxt=NULL;
			}
	    	else if(t2==NULL)
	    	  {
			      t1->prev=NULL;
	    	      start=t1->nxt;
	          }
	    	else
	    	{
	   	    	t2->nxt=t1->nxt;
	    	    t1->nxt->prev=t2;
	        }    
	         delete t1;

		}
	    
}
void DLL::dltAtLast()
{
	node *t1,*t2;
	t1=start;
	if(start==NULL)
	   cout<<"List is Empty:"<<endl;
	else
	   {
	       while(t1->nxt!=NULL)
	       {
	       	   t2=t1;
	           t1=t1->nxt;
		   }
		   if(t2==NULL)
		      start=NULL;
		   else
		   {
		   	  t1->prev=NULL;
		      t2->nxt=NULL;
		   }
		   delete t1;
	   }
	
}
void DLL::dltAtFirst()
{
	node *t1;
    	t1=start;
    	t1->prev=NULL;
    	start=t1->nxt;
    	delete t1;
}
void DLL::inputAtMid(int value,int data)
{
	node *n=new node,*t;
	n->item=data;
	t=start;
	while(t)
	{
		if(t->item==value)
		break;
		t=t->nxt;
	}
	if(t!=NULL)
	{
		n->nxt=t->nxt;
		n->prev=t;
		if(t->nxt!=NULL)
		   t->nxt->prev=n;
		t->nxt=n;
	}
	else
	{
		cout<<"Value not found or List is empty:"<<endl;
	}
}
void DLL::inputAtLast(int data)
{
	node *n=new node;
	n->item=data;
	n->nxt=NULL;
	if(start==NULL)
	{
		n->prev=NULL;
		start=n;
	}
	else
	{
		node *t;
		t=start;
		while(t->nxt!=NULL)
		{
			t=t->nxt;
		}
		t->nxt=n;
		n->prev=t;
	}
}
void DLL::ViewList()
{
	node *t;
	t=start;
	while(t)
	{
		cout<<t->item<<" ";
		t=t->nxt;
	}
}
void DLL::inputAtFirst(int data)
{
	node *n=new node;
	n->item=data;
	n->prev=NULL;
	n->nxt=start;
	
	if(start)
	    start->prev=n;
		start=n;
}

int main()
{
	system("color a");
	DLL l1;
	l1.inputAtFirst(12);
	l1.inputAtLast(98);
	l1.inputAtLast(121);
	//l1.dltAtFirst();
	l1.inputAtMid(12,55);
	//l1.dltAtLast();
	l1.dltatAtMid(121);
	l1.dltatAtMid(12);
	l1.ViewList();
	
	getch();
}