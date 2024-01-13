#include <bits/stdc++.h>
using namespace std;

int solve(int prev, int curr, vector<int> &nums,vector<vector<int>> dp)
{
    if (curr == nums.size())
        return 0;

    if(dp[prev+1][curr]!=-1)
        return dp[prev+1][curr];

    int op1 = 0;
    if (prev == -1 || nums[prev] < nums[curr])
        op1 = 1 + solve(curr, curr + 1, nums,dp);

    int op2 = solve(prev, curr + 1, nums,dp);

    return dp[prev+1][curr]=max(op1, op2);
}

int lengthOfLis(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size(),-1));
    return solve(-1, 0, nums,dp);
}
int main(){
   
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout << lengthOfLis(arr) << endl;

  return 0;
}