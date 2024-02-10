#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &nums, vector<int> &dp)
{

    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    // Include
    // if i am pick index ind then i can't pick ind-1 index
    int pick = nums[ind] + solve(ind - 2, nums, dp);

    // Not Include
    int notPick = 0 + solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int rob(vector<int> &nums)
{

    int n = nums.size();
    // why dp size is n not n+1 because we are using 0 based indexing and we are using n-1 as base case
    vector<int> dp(n, -1);

    return solve(n - 1, nums, dp);
}

int rob2(vector<int> &nums){

    int n = nums.size();
    int dp[n];
    dp[0] = nums[0];
    int neg = 0;

// 0 is done so start from 1 
    for(int i = 1; i < n; i++){

        int take = nums[i];
        if(i>1) take+=dp[i-2];
        int nonTake = dp[i-1];
        dp[i] = max(take, nonTake);
    }

    return dp[n-1];
}

// space optimization 
int rob3(vector<int> &nums){

    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++){

        int take = nums[i];
        if(i>1) take+=prev2;
        int nonTake = prev;
        int curr = max(take, nonTake);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{

//     Input: nums = [1,2,3,1]
// Output: 4
   
    vector<int> nums = {2,7,9,3,1};
    cout << rob3(nums) << endl;

    return 0;
}