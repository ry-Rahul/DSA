#include<iostream>    // Selection sort  works like our brain works
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std; 
void show(int a[])
{
   	for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
        cout<<endl;
} 
int minvalueindex(int a[],int i,int n)
{
	int min,minindex;
	min=a[i];
	for(minindex=i;i<=n-1;i++)
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
	int t,minindex,i;
	for(i=0; i<=n-2; i++)
	{
		minindex=minvalueindex(a,i,n);
		t=a[i];
		a[i]=a[minindex];
		a[minindex]=t;
	}
}

int main()
{
	system("color a");
	int i,j,k;
	int a[]={99,53,61,74,12,31,59,82,41,7};
	cout<<"<<-----Selection sort----->>"<<endl;
	cout<<endl;
	show(a);
	   selection_sort(a,10);
	   cout<<endl;
    show(a);
   	getch();
}