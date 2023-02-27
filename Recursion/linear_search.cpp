#include <bits/stdc++.h>
using namespace std;

bool recursivelinear(int *arr,int size,int key)
{
    if(size==0)
        return false;
    
    if(arr[0]==key)
        return true;

    recursivelinear(arr + 1, size - 1, key);
}


int main()
{
    int arr[] = {2, 5, 8, 9, 3, 46, 56, 99, 100, 150};

    int ans = recursivelinear(arr, 10, 8);
    if(ans)
        cout << "Element is present in array" << endl;
    else
        cout << "element is not present in this array" << endl;

    return 0;
}