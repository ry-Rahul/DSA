#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = 0;

    while(s<=e){
        mid = s + (e-s)/2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] >= nums[s]){
            if(target>=nums[s] && target<nums[mid])
                e = mid-1;
            else
                s = mid+1;
        }
        else{
            if(target>nums[mid] && target<=nums[e])
                s = mid+1;
            else
                e = mid-1;
        }
    }
    return -1;
}

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main(){
    

    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<search(arr,target)<<endl;
  

  return 0;
}