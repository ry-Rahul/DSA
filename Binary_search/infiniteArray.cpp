#include <bits/stdc++.h>
using namespace std;

int findInfiniteArr(int arr[],int size , int target){
     int low = 0;
     int high = 1;
     int mid;

     while (target> arr[high])
     {
        low = high;
        high = high*2;
     }

     cout<<"low "<<low<<" high "<<high<<endl;

     while (low<=high){
         mid = low + (high - low)/2;

         if(target==arr[mid]){
            return mid;
         }
         else if(target > arr[mid]){
            low = mid +1;
         }
         else
            high = mid -1;
     }
     

     return -1;
     
}
int main(){
   int arr[] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   int target  = 0;
   cout<<findInfiniteArr(arr,19,target)<<endl;

  return 0;
}