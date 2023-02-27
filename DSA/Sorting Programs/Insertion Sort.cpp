#include<iostream>    // Insertion Sort;
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
void function(int a[],int n)
{
	int i,j,temp,round,flag=1;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>temp)
			{
				a[j+1]=a[j];
			}
			else
			break;
		}
		a[j+1]=temp;
    }
}
int main()
{
	system("color b");
	int i,j,k;
	int a[]={99,53,61,74,12,31,59,82,41,7};
	cout<<"Array without short-->  ";
	show(a);
	function(a,10);
	cout<<"Array with short   -->  ";
    show(a);
    
   	getch();
}