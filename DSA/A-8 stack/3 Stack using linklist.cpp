#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
class stack
{
	private:
	struct node
    {
	    int item;
	    node *nxt;
    };
    struct node *start;
    
    public:
       stack()  {start=NULL;}
	void pushback(int data);
	void popback();
	void viewStack();
};
void stack::viewStack()
{
	node *t;
	t=start;
	while(t)
	{
		cout<<t->item<<" ";
		t=t->nxt;
	}
}
void stack::pushback(int data)
{
	node *n=new node;
	n->item=data;
	if(start==NULL)
	    n->nxt=NULL;
	else
	    n->nxt=start;
		start=n;
}
void stack::popback()
{
	node *t;
	t=start;
	if(start==NULL)
	  cout<<"Stack is empty:"<<endl;
	else
	{
		start=t->nxt;
		delete t;
	}
}
int main()
{
	system("color a");
	stack s1;
	s1.pushback(45);
	s1.pushback(12);
	s1.pushback(32);
	s1.pushback(55);
	s1.pushback(10);
	s1.popback();
	s1.viewStack();
	
	getch();
}