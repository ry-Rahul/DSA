#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
class Queue
{
	private:
		int capacity;
		int front,rear;
		int *ptr;
	public:
		Queue()
		{ ptr=NULL; }
		
		void createQueue(int cap);
		void insertData(int data);
		void dltData();
		int getFront();
		int getRear();
};
int Queue::getRear()
{
	if(rear!=-1)
	   return ptr[rear];
}
int Queue::getFront()
{
	if(front!=-1)
	   return ptr[front];
}
void Queue::dltData()
{
	if(front==-1)
	     cout<<"Queue underflow:"<<endl;
	else if(rear==front)
	     {
	     	front=-1;
		    rear=-1;
		 }
	else if(front==capacity-1)
	     front=0;
	else
	     front++;
		 
}
void Queue::insertData(int data)
{
	if(ptr)
	{
		if(front==0 && rear==capacity-1 || rear+1==front)
		    cout<<"Queue is Overflow :"<<endl;
		else if(rear==-1)
		{
			front=rear=0;
			ptr[rear]=data;
		}
		else if(rear==capacity-1)
		{
			rear=0;
			ptr[rear]=data;
		}
	    else
	    {
	    	rear++;
	    	ptr[rear]=data;
		}
	}
}
void Queue::createQueue(int cap)
{
	if(ptr==NULL)
	{
    	capacity=cap;
	    front=-1;
	    rear=-1;
	    ptr=new int[cap];
	}
}
int main()
{
	
	Queue q1;
	q1.createQueue(5);
	q1.insertData(10);
	q1.insertData(20);
	q1.insertData(30);
	
	q1.dltData();
	
	cout<<q1.getFront()<<" ";
	cout<<q1.getRear()<<" ";
	
	getch();
}