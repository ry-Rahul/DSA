#include<iostream>   //Assignment-1 , Warm up;
#include<conio.h>
#include<windows.h>
#include<string>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
class Employee
{
	private:
		int empid;
		char name[20];
		float salary;

	public:
		void setemployee(int empid,char n[],float salary)
		{
			this->empid=empid;
			strcpy(name,n);
			this->salary=salary;
		}
		void getemployee() {cout<<empid<<"  "<<name<<"  "<<salary<<endl;}
		
		void setempid(int empid) {this->empid=empid;}
		void setname(char n[]) {strcpy(name,n);}
		void setsalary(float salary) {this->salary=salary;}
		
		int getid() {return empid;}
		char* getname() {return name;}
		float getsalary() {return salary;}

};
Employee salary(Employee obj[])
{
	Employee emp;
	int i;
    for(i=0; i<5; i++)
     if(obj[i].getsalary>obj[i+1].getsalary)
     {
     	
	 }
}
int main()
{
	int i;
	system("color a");
	Employee emp[5];
	emp[0].setemployee(1,"Rahul yadav",250000);
	emp[1].setemployee(2,"Rohit kumar",350000);
	emp[2].setemployee(3,"Harsh raj  ",240000);
	emp[3].setemployee(4,"Shriniwas  ",230000);
	emp[4].setemployee(4,"Aman       ",220000);

	for(i=0; i<5; i++) {
		emp[i].getemployee();
	}



	getch();
}