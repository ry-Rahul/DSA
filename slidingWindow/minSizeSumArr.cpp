#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int ans=INT_MAX;
        
        while(j<n){
        //       2,3,1,2,4,3
            sum+=nums[j];
            
            while(sum>=target){
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            
            j++;
        }
        
        return (ans==INT_MAX)?0:ans;
    }
int main(){
  

    // Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
    vector<int> nums={2,3,1,2,4,3};
    int target=7;

    cout<<minSubArrayLen(target,nums)<<endl;
  return 0;
}