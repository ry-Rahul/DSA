#include<iostream> // Modified Bubble sort
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
	using namespace std;
void show(int a[])
{
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
}
void function(int a[], int n)
{
	int i, j, temp, round, flag = 1;
	for (round = 1, flag = 1; round <= n - 1; round++)
	{
		// temp=a[i];
		for (j = 0; j <= n - 1 - round; j++)
		{
			temp = a[j];
			if (a[j] > a[j + 1])
			{
				flag = 0;
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		if (flag)
			break;
	}
}
int main()
{
	system("color b");
	int i, j, k;
	int a[] = {99, 53, 61, 74, 12, 31, 59, 82, 41, 7};
	show(a);
	function(a, 10);
	show(a);

	getch();
}