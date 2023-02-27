#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr,int size)
{
    if(size==0 || size ==1)
        return;
    
    for (int i = 0; i < size; i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i], arr[i + 1]);
    }

    bubbleSort(arr, size - 1);
}

void print(int *arr,int count)
{
     for (int i = 0; i < count; i++)
     {
         cout << arr[i];
         if(i!=count-1)
             cout << " -> ";
     }
     cout << endl;
}

int main()
{             // 0   1   2    3   4   5   6   7   8  9  10 11 12  13
    int arr[] = {78, 45, 96, 33, 12, 56, 14, 19, 20, 1, 2, 5, 7, 9};
    print(arr, 14);
    bubbleSort(arr, 14);
    print(arr, 14);

    return 0;
}