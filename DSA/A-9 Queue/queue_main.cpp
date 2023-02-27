#include<iostream>
#include<conio.h>
using namespace std;
class queue
{
	private:
		int capacity;
		int front;
		int rear;
		int *ptr;
	public:
	    queue(){ptr==NULL;}
		void creatarray(int cap);
		//void creatarray(int cap);
		void insert(int data);
		void showqueue();
};
void queue::showqueue()
{
	for(int i=0; i<capacity; i++)
	    cout<<ptr[i]<<" ";
}
void queue::insert(int data)
{
		if(ptr==NULL)
		{
	        if(front==0 && rear==capacity-1 || rear==0)
	             cout<<"Queue is full:"<<endl;
	        else if(rear==-1)
	        {
	        	rear=front=0;
	            ptr[rear]==data;
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
void queue::creatarray(int cap)
{
	if(cap>0)
	{
	    capacity=cap;
	    front=-1;
	    rear=-1;
	    ptr=new int[capacity];
	}
}
int main()
{
	system("color b");
	queue q1;
	q1.creatarray(5);
	q1.insert(55);
	q1.insert(45);
	q1.insert(89);
	q1.insert(100);
	//q1.insert(55);
	//q1.insert(55);
	q1.showqueue();
}