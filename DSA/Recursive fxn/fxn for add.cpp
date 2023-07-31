#include<iostream>
#include<conio.h>
using namespace std;

float sumofNat(int n)
{
	if(n==1)
	  return 1;
	else
	{
		if(n%2==1)
	   return sumofNat(n-1)+(float)1/n;
	   else
	   return sumofNat(n-1)-(float)1/n;
	}
}
int main()
{
	int n;
	cout<<"enter a number"<<endl;
	cin>>n;
	cout<<sumofNat(n);
	getch();
	return 0;
}