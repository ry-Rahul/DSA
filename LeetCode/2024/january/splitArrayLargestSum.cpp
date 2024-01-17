#include <bits/stdc++.h>
using namespace std;

/* Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

Example 1:

Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits.  */


class Solution {
public:
    int no_of_subArray_withMax_sum_as_mid(vector<int> nums,int mid){
        int sum=0;
        int cnt=1;
        //mid = 10
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]>mid){
                cnt++;
                //3 6 2 8 4
                sum=nums[i];
            }else if(mid>sum){
                // mid is greater than so sum it 
                // at mid less then 
                sum+=nums[i];

                // 3 6 
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans=low;

        while(low<=high){
            int mid = low + (high-low)/2;
            int n = no_of_subArray_withMax_sum_as_mid(nums,mid);

            if(n>k){
                //very low value of mid
                low= mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};

int main(){
  

  return 0;
}