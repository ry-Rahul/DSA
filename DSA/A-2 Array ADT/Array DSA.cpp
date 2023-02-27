#include<iostream>   
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;
class ADT
{	private:
		int capacity;
		int lastindex;
		int *ptr;
	public:
		//int count=0

		void creatarr(int cap)
		{
			ptr=new int[cap];
	    	capacity=cap;
			lastindex=-1;

//			for(int i=0; i<capacity; i++)
//				*(ptr+i)=0;
		}
		void append(int data)
		{	if(lastindex==capacity-1)
			{	cout<<"Array  overflow:"<<endl;
			}
			else
			{	lastindex++;
				ptr[lastindex]=data;
			}
			//count++;
		}
		void show()
		{	for(int i=0; i<capacity; i++)
			{	cout<<*(ptr+i)<<"  ";
			}
		}
		void dltele(int index)
		{	
		    if(index<0 || index>lastindex)
		        cout<<"Invalid index:"<<endl;
		    else
		    {
		    	for(int i=index; i<=lastindex-1; i++)
			      	ptr[i]=ptr[i+1];
			   
		            lastindex--;
			}

		}

		void insert(int index,int data)
		{	if(index<0 || index>lastindex+1)
				cout<<"Operation failed: Invalid index"<<endl;
			else if(lastindex==capacity-1)
			     cout<<"Operation failed: Array overflow"<<endl;
			else
			{

				for(int i=lastindex; i>=index; i--)
					ptr[i+1]=ptr[i];
				ptr[index]=data;
				lastindex++;
			}
		}

		int getelem(int index)
		{	if(index<0 || index>lastindex)
				cout<<"Operation failed, Invalid index"<<endl;
			else
			    return ptr[index];
		}
		int count()
		{	int k;
			k=lastindex+1;
			return k;
		}
		void edit(int index,int data);
		int search(int data);
};
int ADT::search(int data)
{
	for(int i=0; i<=lastindex; i++)
	    {
	    	if(ptr[i]==data)
	        return i;
	        return -1;
		}
	
}
void ADT::edit(int index,int data)
{
	if(index<0 || index>lastindex)
	  cout<<"Operation failed: Invalid index"<<endl;
	else
	{
		ptr[index]=data;
	}
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
	cout<<endl<<"Enter your Option";
	cin>>choice;
	return choice;
	
}
void viewarray(ADT &arr)
{
	int i;
	cout<<endl;
	for(i=0; i<arr.count(); i++)
	   cout<<arr.getelem(i)<<"  ";
	   
}
int main()
{	
    system("color a"); 
    int i,index,data; 
	ADT arr1;
	arr1.creatarr(6);
	while(true)
	{
		system("cls");
		cout<<"\nTotal number of elements:"<<arr1.count();
		viewarray(arr1);
		switch(menu())
		{
			case 1:
				cout<<"Enter data to Append:";
				cin>>data;
				arr1.append(data);
			    break;
			case 2:
				cout<<"Enter data to Insert:";
				cin>>data;
				cout<<"Enter Index to insert:";
				cin>>index;
				arr1.insert(index,data);
				break;
			case 3:
				cout<<"Enter index for delete:";
				cin>>index;
				arr1.dltele(index);
				break;
			case 4:
				cout<<"Enter data to edit:";
				cin>>data;
				cout<<"Enter index:";
				cin>>index;
				arr1.edit(index,data);
				break;
			case 5:
				cout<<"Enter data for search:";
				cin>>data;
				index=arr1.search(data);
				if(index=-1)
				    cout<<"Array empty Search Failed:";
				else
				    cout<<"Element found at index= "<<index;
				break;
			case 6:
				exit(0);
			default:
				cout<<"Invalid Choice";
		}
		getch();
	}
	
	
}