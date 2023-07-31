#include<iostream>    // A-10 a) Two way stack using array:
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;  
class twstack
{
	private:
		int capacity;
		int topleft,topright;
	    int *ptr;
	public:
		
		twstack(int cap)
		{ capacity=cap; topleft=-1; topright=capacity; ptr=new int[capacity];}
		
		~twstack() {delete []ptr;}
		
		bool isFull(); 
		bool isEmptyLeft(); 
		bool isEmptyRight(); 
		void peekRight();
		void peekLeft();
		void pushLeft(int data);
		void pushRight(int data);
		void popLeft();
		void popRight();
};
void twstack::popRight()
{
	if(isEmptyRight())
	    cout<<"stack is Empty:"<<endl;
	else
	    topright++;
}
void twstack::popLeft()
{
	if(isEmptyLeft())
	    cout<<"stack is Empty:"<<endl;
	else
	    topleft--;
}
void twstack::pushRight(int data)
{
	if(isFull())
	    cout<<"Stack is overflow:"<<endl;
	else
	{
		topright--;
        ptr[topright]=data;
	}
	
}
void twstack::pushLeft(int data)
{
	if(isFull())
	    cout<<"Stack is overflow:"<<endl;
	else
	{
		topleft++;
		ptr[topleft]=data;
	}
	
}
void twstack::peekRight()
{
	if(isEmptyRight())
	     {
		     cout<<"Stack underflow: "<<endl;
		 }
	else
    	 cout<<ptr[topright]<<" "<<endl;
}
void twstack::peekLeft()
{
	if(isEmptyLeft())
	    {
		    cout<<"Stack underflow: "<<endl;
		}
	else
	      cout<<ptr[topleft]<<" "<<endl;
}
bool twstack::isEmptyRight()
{
	return topright==capacity;
}
bool twstack::isEmptyLeft()
{
	return topleft==-1;
}
bool twstack::isFull()
{
	     return topleft+1==topright;
}

int main()
{
	system("color b");
	twstack s1(4);
    s1.pushLeft(10);
    s1.pushLeft(110);
    s1.pushRight(20);
//    s1.pushRight(30);
//    s1.popLeft();
//    s1.popRight();
      s1.peekLeft();
      s1.peekRight();
    
   	getch();
}