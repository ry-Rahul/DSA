#include<iostream>
using namespace std;

struct  temp
{
	int min,max;
	void input(int x,int y)
	{
		min=x;
		max=y;
	}
	void display()
	{
		cout<<min<<"c  "<<max<<"c  "<<endl;
	}

    int minavg(struct temp);
};

int main()
{
	system("color a");
	int i,j;
	struct temp t1,t2,t3,t4,t5;
	t1.input(35,44);
	t2.input(34,41);
	t3.input(18,35);
	t4.input(15,30);
	t5.input(6,25);


}