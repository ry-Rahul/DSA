#include <bits/stdc++.h>
using namespace std;


void merge(int arr[],int low, int mid, int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

     for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
     }
    
}

void mergesort(int *arr,int low,int high)
{
    int mid = low + (high - low) / 2;
    if(low>=high)
        return;
    
    // left merge
    mergesort(arr, low, mid);

    // Right merge
    mergesort(arr, mid + 1, high);
    
    // merge
    merge(arr, low, mid, high);
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
//   printarr(arr, 14);
  mergesort(arr, 0, 13);
    printarr(arr, 14);
  return 0;
}