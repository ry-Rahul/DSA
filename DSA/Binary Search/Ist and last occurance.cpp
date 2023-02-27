#include<iostream>    // Q Binary search 1st and last occurance of an element
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int length(int a[])
{
	int i;
	for(i=0; a[i]; i++);
	return i;
} 
void show(int a[])
{
   	for(int i=0;i<length(a);i++)
        cout<<a[i]<<" ";
        cout<<endl;
        cout<<endl;
} 

int quick(int a[],int left,int right)
{
	int i,loc,t;
	loc=left;
	while(left<right)
	{
		while(left<right && a[loc]>=a[right])
		     right--;
		if(left==right)
		     break;
		else
		{
			t=a[loc];
			a[loc]=a[right];
			a[right]=t;
			loc=right;
		}
		
		while(left<right && a[loc]<=a[left])
		     left++;
		if(left==right)
		     break;
		else
		{
			t=a[loc];
			a[loc]=a[left];
			a[left]=t;
			loc=left;
		}
	}
	return loc;
}
void Quick_sort(int a[],int l,int u)
{
	int loc,i,t;
	loc=quick(a,l,u);
	if(l+1<loc)
	    Quick_sort(a,l,loc-1);
	if(u-1>loc)
	    Quick_sort(a,loc+1,u);
	
}
int minvalueindex(int a[],int i,int n)
{
	int min,minindex;
	    min=a[i];
	for(minindex=i; i<n; i++)
	{
		if(min>a[i])
		{
			min=a[i];
			minindex=i;
		}
	}
	return minindex;
}
void selection_sort(int a[],int n)
{
	int i,t,minindex;
	for(i=0; i<=n-2; i++)
	{
		minindex=minvalueindex(a,i,n);
			if(a[i]>a[minindex])
			{
				t=a[i];
			    a[i]=a[minindex];
			    a[minindex]=t;
			}
	}
}
int binary_search(int a[],int data)
{
	int start,end,mid,result;
	start=0;
	end=length(a)-1;
	
	while(start<=end)
	{
		mid=start+(end-start)/2;
		if(a[mid]==data)
		{
			result=mid;
			start=mid+1;			
		}
		else if(a[mid]>data)
		     end=mid-1;
		else
		     start=mid+1;
	}
	   return result;
}
int main()
{
	system("color a");
	
	int a[]={20,10,2,10,4,18,10,10};
	int n;

	cout<<"<<-----Binary-search----->>"<<endl;
	//cout<<"<<-----sorting in Dessending order----->>"<<endl;
	cout<<endl;
	show(a);
	    selection_sort(a,length(a));
	    show(a);
//	    cout<<"Enter a number for searching"<<endl;
//	    cin>>n;
    cout<<binary_search(a,10);
	
    //show(a);
    
    
   	getch();
}