#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[],int target) {

  cout<<"target "<<target<<endl;

        int start=0,mid;
        int end=1;
        int res = -1;

        // find the range
        while(arr[end] < target){
            start = end;
            end = end*2;
        }

        cout<<"start "<<start<<" end "<<end<<endl;

        while (start <= end) {
            mid = start + (end - start)/2;

            if(arr[mid] == target){
                res = mid;
                end = mid -1;
            }
            else if(arr[mid] > target){
                end = mid -1;
                }
            else
                start = mid +1;

        }

        return res;
}
int main(){
   
   int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    int target = 1;

    cout<<firstOccurence(arr,target)<<endl;



  return 0;
}