// leetcode 852

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s = 0;
        int e = arr.size();
        int mid = 0;

        while(s<e){
            mid = s + (e-s)/2;

            if(arr[mid]<arr[mid+1]){
                s = mid +1;
            }
            else if(arr[mid]){
                e = mid;
            }
        }
        return e;
    }
};


int main(){
  

  return 0;
}
