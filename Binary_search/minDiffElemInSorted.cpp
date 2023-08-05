#include <bits/stdc++.h>
using namespace std;

int minDiffElem(int arr[],int size,int target) {

        int start=0,mid;
        int end = size -1;
        int res = -1;

        while (start <= end) {
            mid = start + (end - start)/2;

            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                end = mid -1;
                }
            else
                start = mid +1;

        }

        if(abs(arr[start]-target) < abs(arr[end]-target))
            return abs(arr[start]-target);
        else
            return abs(arr[end]-target);
        
}

int main(){
  
    int arr[] = {1,3,8,10,12,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 12;

    cout<<minDiffElem(arr,size,target)<<endl;

  return 0;
}