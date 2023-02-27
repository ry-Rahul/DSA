#include <bits/stdc++.h>
using namespace std;

int recursiveBinary(int *arr, int start,int end, int key)
{
    int mid = start + (end - start) / 2;
    cout <<"mid value = "<< arr[mid] << " " << endl;
    if (start>end)
        return -1;

    else if (arr[mid] == key)
        return mid;

    else if(arr[mid]>key)
        recursiveBinary(arr,start,mid-1, key);

    else if(arr[mid]<key)
        recursiveBinary(arr,mid+1,end, key);
}

int main()
{
    int arr[] = {2, 3, 5, 8, 9, 46, 56, 99, 100, 150};

    int ans = recursiveBinary(arr,0,9,46);
    if (ans>=0)
        cout << "Element is present in array at index -> " <<ans << endl;
    else
        cout << "element is not present in this array" << endl;

    return 0;
}