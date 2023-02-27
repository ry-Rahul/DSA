#include <bits/stdc++.h>
using namespace std;

void merge(int *arr,int start,int end)
{
    int mid = start + (end - start) / 2;
    int val1 = mid - start + 1;
    int val2 = end - mid;

    int *first = new int[val1];
    int *second = new int[val2];

    int k = start;
    for (int i = 0; i < val1; i++)
        first[i] = arr[k++];

    k = mid + 1;
    for (int i = 0; i < val2; i++)
        second[i] = arr[k++];
    

    int index1 = 0;
    int index2 = 0;
    k = start;

    while (index1<val1 && index2<val2)
    {
        if(first[index1]<second[index2])
            arr[k++] = first[index1++];
        
        else
            arr[k++] = second[index2++];
    }
    while (index1<val1)
        arr[k++] = first[index1++];
    

    while (index2 < val2)
         arr[k++] = second[index2++];

    // cout << "hii";
}

void mergesort(int *arr,int s,int e)
{
    int mid = s + (e - s) / 2;
    if(s>=e)
        return;
    
    // left merge
    mergesort(arr, s, mid);

    // Right merge
    mergesort(arr, mid + 1, e);
    
    // merge
    merge(arr, s, e);
}

void printarr(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if(i!=size-1)
            cout << " ,";
    }
    cout << endl;
}

int main()
{
  int arr[]={13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  printarr(arr, 14);
  mergesort(arr, 0, 14);
  printarr(arr, 14);

  return 0;
}