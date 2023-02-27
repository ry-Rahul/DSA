#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int linearSearch(int a[],int data)
{
	int i;
	for(i=0; a[i]; i++)
	{
		if(a[i]==data)
		break;
	}
	if(a[i]!=NULL)
	   return i;
	else 
	   return -1;

}
int main()
{
	system("color a");
	int a[]={10,23,14,25,89,654,236,124,78,19,20,320};
	cout<<"Value is found on Index = ";
	cout<<linearSearch(a,236);
	getch();
	
}