#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int maxvalue(int A[],int size)
{   int i,max=0;
    for(i=0; i<size; i++)
    {   if(max<A[i])
            max=A[i];
    }
    return max;
}

int avg(int A[],int size)
{   int i,sum=0;
    for(i=0; i<size; i++)
    {   sum=sum+A[i];
    }
    return (sum/size);
}
int sum(int A[],int size)
{   int i,sum=0;
    for(i=0; i<size; i++)
    {sum=sum+A[i];}
    
    return (sum);
}
int* createarr(int A[],int B[])
{   int i,j,k,*ptr;

    for(i=0; A[i]; i++);
    for(j=0; B[j]; j++);

    ptr=new int[i+j];
    for(i=0; A[i]; i++)
    {   ptr[i]=A[i];
    }
    for(j,k=0; B[k]; k++,j++)
    {   ptr[j]=B[k];
    }
    return ptr;
}
int main()
{   system("color a");
    int *ptr,i;
    int arr1[]= {5,15,25,35,45};
    int arr2[]= {10,20,30,40,50};
    //cout<<maxvalue(arr1,5);
    //cout<<endl;
    //cout<<avg(arr1,9);
    //cout<<endl;
    //cout<<sum(arr1,9);
    //cout<<endl;
    ptr=createarr(arr1,arr2);
    for(i=0; i<10; i++)
        cout<<ptr[i]<<"  ";
    getch();
}