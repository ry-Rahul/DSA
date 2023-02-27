#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
class CLL
{
	private:
	struct node
    {
	    int item;
	    node *nxt;
    };
    struct node *last;
    
    public:
       CLL()  {last=NULL;}
	void insertAtFirst(int data);
	void insertAtLast(int data);
	void insertAtMid(int value,int data);
	void dltFirst();
	void dltLast();
	//void dltAtPosition();
	void viewData();
//	~CLL()
//	{
//		while(last)
//		  delete dltFirst();
//	}
};
void CLL::viewData()
{
	node *t=NULL;
	//t=last;
	t=last->nxt;
	//cout<<t->item<<" ";
	while(t->nxt!=last)
	    {
	       	cout<<t->item<<" ";
	       	t=t->nxt;
		}
}
//void CLL::dltAtPosition()
//{
//	
//}
void CLL::dltLast()
{
	node *t;
	if(last)
	{
		if(last->nxt==NULL)
		{
			delete last;
			last=NULL;
		}
		else
		{
			t=last->nxt;
			while(t->nxt!=last)
		        t=t->nxt;
		    t->nxt=last->nxt;
		    delete last;
		    last=t;
        }
    }
    else
    cout<<"Underflow  :("<<endl;
}
void CLL::dltFirst()
{
	node *t;
	t=last->nxt;
	if(last)
	{
		if(last->nxt==NULL)
		{
			delete last;
			last=NULL;
		}
		else
		{
			t=last->nxt;
			last->nxt=t->nxt;
			delete t;
		}
	}
	else
	cout<<"Underflow :("<<endl;
}
void CLL::insertAtMid(int value,int data)
{
	node *n,*t;
	t=last->nxt;
	while(t)
	    {
	    	if(t->item==value)
	    	break;
		    t=t->nxt;
	    }
	if(t!=NULL)
	{
		n=new node;
		n->item=data;
		n->nxt=t->nxt;
		t->nxt=n;
	}	
	else
	{
	    cout<<"No item found  :("<<endl;
    }  	
	
	
	
}
void CLL::insertAtLast(int data)
{
	node *n=new node;
	n->item=data;
	if(last==NULL)
	{
		n->nxt=n;
		last=n;
	}
	else
	{
		n->nxt=last->nxt;
		last->nxt=n;
		last=n;
	}
}
void CLL::insertAtFirst(int data)
{
	node *n=new node;
	n->item=data;
	if(last==NULL)
	{
		n->nxt=n;
		last=n;
	}
	else
	{
		n->nxt=last->nxt;
	    last->nxt=n;
	}
}

int main()
{
	system("color a");
	CLL l1;
	l1.insertAtFirst(50);
	l1.insertAtLast(25);
	l1.insertAtMid(50,55);
	//l1.dltFirst();
	//l1.dltLast();
	l1.viewData();
	
	getch();
}