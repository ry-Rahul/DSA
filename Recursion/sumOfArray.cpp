#include <bits/stdc++.h>
using namespace std;

int sumOfArray(int arr[],int size){
    if(size==0)
        return 0;
    if(size==1)
        return arr[0];
    
    int sum = arr[0] + sumOfArray(arr+1,size-1);
    return sum;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum of Array is: " << sumOfArray(arr,size) << endl;

  return 0;
}