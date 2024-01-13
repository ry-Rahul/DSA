#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
class stack  // 1. Stack Using Array
{
	private:
	int capacity;
	int lastindex;
	int *ptr;
	
    public:
    
	void createArray(int cap);
	void popback();
	void pushback(int data);
	int count();
	int getElement(int i);
	
};
int stack::getElement(int i)
{
	return ptr[i];
}
int stack::count()
{
	return lastindex+1;
}
void stack::popback()
{
	if(lastindex<0)
	  cout<<"Stack is empty :(";
	else
	{
		
		   int i=lastindex;
		    ptr[i]=ptr[i+1];
			lastindex--;
	
	}
}
void stack::pushback(int data)
{
	if(lastindex==capacity-1)
	   cout<<"Stack is overflow only "<<lastindex+1<<" values contain -> ";
	else
	{
		lastindex++;
		ptr[lastindex]=data;
	}
}
void stack::createArray(int cap)
{
	capacity=cap;
	lastindex=-1;
	ptr=new int[capacity];
}

void viewStack(stack &stk)
{
	int i;
	for(i=0; i<stk.count(); i++)
	 cout<<stk.getElement(i)<<" ";
}
int main()
{
	
	int data;
	stack s1;
	int n,t;
	cin>>n
	s1.createArray(n);

	cin >> t;
	while(t--)
	{
		int data;
		cin >> Data;
		s1.pushback(data);
	}
	s1.getElement();
}