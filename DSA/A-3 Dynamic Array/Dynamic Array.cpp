#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;
class DynamicArray
{
	private:
		int lastindex;
		int capacity;
		int *ptr;
	public:
		void Createarray(int cap);
		void Append(int data);
		void Insert(int data,int index);
		int Count();
		int Getitem(int index);
		void Dltitem(int index);
		void Editdata(int index,int data);
		int Searchitem(int data);
		void DoubleArray();
		void HalfArray();
		~DynamicArray();
};
DynamicArray::~DynamicArray()
{
	delete []ptr;
}
void DynamicArray::HalfArray()
{
	int i,*temp;
	capacity/=2;
	temp=new int[capacity];
	for(i=0; i<=lastindex; i++)
	    temp[i]=ptr[i];
	delete []ptr;
	ptr=temp;
}
void DynamicArray::DoubleArray()
{
	int *temp,i;
	capacity*=2;
	temp=new int[capacity];
	for(i=0; i<=lastindex; i++)
	   temp[i]=ptr[i];
	delete []ptr;
	ptr=temp;
	    
}
int DynamicArray::Searchitem(int data)
{
	
	for(int i=0; i<=lastindex; i++)
		if(ptr[i]==data)
		    return i;
			return -1;

	        
}
void DynamicArray::Editdata(int index,int data)
{
	if(index<0 || index>lastindex)
	cout<<"Operation fail: Invalid index"<<endl;
	else
	ptr[index]=data;
	
}
void DynamicArray::Dltitem(int index)
{
	if(index<0 || index>lastindex)
	cout<<"Operation fail: Invalid index"<<endl;
	else
	{
		int i;
		for(i=index; i<=lastindex-1; i++)
		ptr[i]=ptr[i+1];
		lastindex--;	
	}
}
int DynamicArray::Getitem(int index)
{
	if(index<0 || index>lastindex)
	cout<<"Operation fail: Invalid index"<<endl;
	else
	 return ptr[index];
}
int DynamicArray::Count()
{
	return lastindex+1;
}
void DynamicArray::Insert(int data,int index)
{
	if(index<0 || index>lastindex+1)
	cout<<"Operation fail: Invalid index"<<endl;
	else if(lastindex==capacity-1)
        DoubleArray();
    else
       {
       	int i;
       	for(i=lastindex; i>=index; i--)
       	    ptr[i+1]=ptr[i];
       	    ptr[index]=data;
       	    lastindex++;
	   }
}
void DynamicArray::Append(int data)
{
	if(lastindex==capacity-1)
	    DoubleArray();
	else
	  {
		lastindex++;
	    ptr[lastindex]=data;
	  }
}
void DynamicArray::Createarray(int cap)
{
	lastindex=-1;
	capacity=cap;
	ptr=new int[cap];
}
int menu()
{
	int choice;
	cout<<endl<<"1. Append";
	cout<<endl<<"2. Insert";
	cout<<endl<<"3. Delete";
	cout<<endl<<"4. Edit";
	cout<<endl<<"5. Search";
	cout<<endl<<"6. Exit";
	cout<<endl<<"Enter your choice  ";
	cin>>choice;
	return choice;
}
void Viewarray(DynamicArray &arr)
{
    int i;
    for(i=0; i<arr.Count();i++)
     cout<<arr.Getitem(i)<<"  ";
}

int main()
{
	system("color a");
	int i,index,data;
	DynamicArray arr1;
	arr1.Createarray(6);
	while(true)
	{
		system("cls");
		cout<<"Total Element in Array : "<<arr1.Count()<<endl;
		Viewarray(arr1);
		
		switch(menu())
		{
			case 1:
				cout<<"Enter data to Append";
				cin>>data;
				arr1.Append(data);
				break;
			case 2:
				cout<<"Enter data to Insert";
				cin>>data;
				cout<<"Enter Index";
				cin>>index;
				arr1.Insert(data,index);
				break;
			case 3:
				cout<<"Enter index for Delete";
				cin>>index;
				arr1.Dltitem(index);
				break;
			case 4:
				cout<<"Enter Index for Edit data";
				cin>>index;
				cout<<"Enter Data";
				cin>>data;
				arr1.Editdata(index,data);
				break;
			case 5:
				cout<<"Enter data to search";
				cin>>data;
				index=arr1.Searchitem(data);
				if(index==-1)
				cout<<"Array empty Search failed";
				else
				 cout<<"Element at index= "<<index;
				break;
			case 6:
				exit(0);
			default:
				cout<<"Invalid choice";
		}
		getch();
	}
	
}