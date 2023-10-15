#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(int ind, int target, vector<int> &nums){
        
        if(target==0)
            return true;
        if(ind==0)
            return target == nums[0];

        bool notTake = solve(ind-1, target, nums);
        bool take = false;
        if(target>=nums[ind])
            take = solve(ind-1, target-nums[ind], nums);

        return take | notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        { 
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        sum = sum/2;

        return solve(n-1, sum, nums);
    }
};

int main(){
  
  vector<int> arr = {1,5,11,5};
    Solution s;
    cout<<s.canPartition(arr)<<endl;

  return 0;
}