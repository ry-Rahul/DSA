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
    int pick = nums[ind] + solve(ind - 2, nums, dp);

    // Not Include
    int notPick = 0 + solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int rob(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n, -1);

    return solve(n - 1, nums, dp);
}

int main()
{

    return 0;
}