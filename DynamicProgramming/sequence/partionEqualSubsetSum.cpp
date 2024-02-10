#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        
        if(target==0)
            return true;
        if(ind==0)
            return target == nums[0];
        if(dp[ind][target]!=-1)
            return dp[ind][target];

        bool notTake = solve(ind-1, target, nums,dp);
        bool take = false;
        if(target>=nums[ind])
            take = solve(ind-1, target-nums[ind], nums,dp);

        return  dp[ind][target] = take | notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(10001, -1));

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        { 
            sum += nums[i];
        }
        
        if(sum%2!=0) return false;
        sum = sum/2;

        // cout<<"sum "<<sum<<endl;

        return solve(n-1, sum, nums,dp);
    }
};

int main(){
// leet code 416
 
//     Input: nums = [1,5,11,5]
// Output: true         
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
  
  vector<int> arr = {1,2,5};
    Solution s;
    cout<<s.canPartition(arr)<<endl;

  return 0;
}
