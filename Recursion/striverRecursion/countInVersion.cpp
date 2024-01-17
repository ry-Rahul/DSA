#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int low, int mid, int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;
    int count = 0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            count+=mid-left+1;
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
    
    return count;
}

int mergesort(int *arr,int low,int high)
{
    int mid = low + (high - low) / 2;
    int cnt = 0;
    if (low >= high)
        return cnt;
    cnt+=mergesort(arr, low, mid);
    cnt+=mergesort(arr, mid + 1, high);
    cnt+=merge(arr, low, mid, high);
    return cnt;
}
int main(){

    int arr[] = {5,2,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt = mergesort(arr,0,n-1);
    cout<<cnt<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  

  return 0;
}