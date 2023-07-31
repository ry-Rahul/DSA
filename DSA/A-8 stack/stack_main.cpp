#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
class stack
{
    private:
    	int capacity;
    	int lastindex;
    	int *ptr;
    public:
	    stack()
		{ capacity=0;  lastindex=-1;  ptr=NULL; } 
		
		 stack(int cap)
		 { capacity=cap; lastindex=-1; ptr= new int[capacity]; }
		 
    	void creatArray(int cap);
    	void popback();
    	void pushback(int data);
    	int count();
    	void peek();
    	bool isFull();
    	bool isEmpty();
    	void showstack();
    	int countt();
};
void stack::showstack()
{
	for(int i=0; i<count() ; i++)
	    cout<<ptr[i]<<" ";
}
void stack::peek()
{
        if(isEmpty())
	        cout<<"stack is Empty:"; 
		else
		    cout<<ptr[lastindex];
}
void stack::popback()
{
	if(isEmpty())
	   cout<<"stack underflow";
	else
	{
		lastindex--;
	}
}
bool stack::isFull()
{
	return lastindex==capacity-1;
}
bool stack::isEmpty()
{
	return lastindex==-1;
}

void stack::pushback(int data)
{
	if(isFull())
	     cout<<"stack is overflow only "<<lastindex+1<<" value contain"<<endl;
    else
    {
    	
    	lastindex++;
    	ptr[lastindex]=data;
	}
}
void stack::creatArray(int cap)
{
	if(cap>0)
    	{
    		if(ptr!=NULL)
    		    delete []ptr;
    		    
	          capacity=cap;
	           ptr=new int[capacity];
	          lastindex= -1;
    	}
}
int menu()
{
	int choice;
	cout<<endl<<"Choose your choice"<<endl;
	cout<<"1.Pushback:"<<endl;
	cout<<"2.Pop back"<<endl;
	cout<<"3.Peek"<<endl;
	
	cin>>choice;
	return choice;
}
int stack::count()
{
      return lastindex+1;	
}
int main()
{
	system("color b");
	stack s1;
	s1.creatArray(5);
	int data;
	while(true)
	{
		system("cls");
		cout<<"Total element in stack "<<s1.count()<<" "<<endl;
		s1.showstack();
		switch(menu())
		{
			case 1:
				cout<<"Enter data to Pushback:";
				cin>>data;
				s1.pushback(data);
			    break;
			case 2:
				s1.popback();
				break;
			case 3:
				exit(0);
			default:
				cout<<"Invalid choice";
	}
	}
	
	
	
    return 0;
}