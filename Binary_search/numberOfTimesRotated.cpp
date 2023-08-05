#include <bits/stdc++.h>
using namespace std;

int findMin(int nums[],int size) {

        int start=0,mid;
        int end = size -1;

        while (start < end) {
            mid = start + (end - start)/2;

            if(nums[mid]>nums[end])
                 start = mid +1;
            else
                end = mid;

        }
        return start;
}

int main(){

    int arr[] = {4,5,6,7,0,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<endl<<"Number of times rotated:";
    cout<<findMin(arr,size)<<endl;

  

  return 0;
}