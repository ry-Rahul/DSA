#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int length(int a[])
{
	int i;
	for(i=0; a[i]; i++);
	  return i;
}
void display(int a[])
{
	int i;
	for(i=0; i<length(a); i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
	  cout<<endl;
}
int minindexvalue(int a[],int i)
{
	int t,min,minindex;
	min=a[i];
	for(i; i<length(a); i++)
	{
		if(min>a[i])
		{
			min=a[i];
			minindex=i;
		}
	}
		return minindex;
}
void selection_sort(int a[])
{
	int minindex,i,t;
	for(i=0; i<length(a)-1; i++)
	{
		minindex=minindexvalue(a,i);
		t=a[i];
		if(a[i]>a[minindex])
		{
			a[i]=a[minindex];
			a[minindex]=t;
		}
	}
}
int binary_search(int a[],int data)
{
	int start=0,end,mid;
	end=length(a);
	while(start<end)
	{
		mid=start+(end-start)/2;
		if(a[mid]==data)
		   return mid;
		else if(a[mid]>data)
		    end=mid-1;
		else
		    start=mid+1;
	}
	return mid;
}
int main()
{
	system("color a");
	int a[]={65,23,14,7,5,1,3,6,45,5,4,66};
	display(a);
	selection_sort(a);
	display(a);
	cout<<binary_search(a,7);
	
	getch();
}




/*
int bineary_search(int a[], int data)
{
     int start=0,mid, end;
     end= length();
     while(start<end)
     {
        mid= start + (-mid)

}

*/