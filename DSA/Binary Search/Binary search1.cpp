#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int length(int a[])
{
	int i=0;
	for(i=0; a[i]; i++);
	   return (i);
}
void display(int a[])
{
	for(int i=0; i<length(a); i++)
	   cout<<a[i]<<" ";
	   cout<<endl;
	   cout<<endl;
}
int quick(int a[],int left,int right)
{
	int loc,t;
	loc=left;
	while(left<right)
	{
		while(a[loc]<=a[right] && left<right)
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
		
		while(a[loc]>=a[left] && left<right)
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
void quick_sort(int a[],int l,int u)
{
	int loc;
	loc=quick(a,l,u);
	if(l+1<loc)
	   quick_sort(a,l,loc-1);
	if(u-1>loc)
	   quick_sort(a,loc+1,u);
}
int binary_search(int a[],int data)
{
	int l=0,u,mid;
	u=length(a);
	
	while(l<u)
	{
		mid=l+(u-l)/2;
		if(a[mid]==data)
		   return mid;
		else
		{
			if(a[mid]>data)
			u=mid-1;
			else
			l=mid+1;
		}
	}
	return mid;
	
}
int main()
{
	system("color a");
	int a[]={98,1,2,36,14,75,21,56,25,48,89,55,13};
	quick_sort(a,0,12);
	display(a);
	cout<<binary_search(a,55);
	getch();
	
}