#include <bits/stdc++.h>
using namespace std;

// count number of subset with sum equal to k
class Solution
{
public:
    int solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (sum == 0 && nums[0] == 0)
                return 2;
            if (sum == 0 || nums[0] == sum)
                return 1;
            return 0;
        }

        int notTake = solve(ind - 1, sum, nums, dp);
        int take = 0;
        if (sum >= nums[ind])
            take = solve(ind - 1, sum - nums[ind], nums, dp);

        return dp[ind][sum] = take + notTake;
    }

    // dp solution
    int subsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, k, nums, dp);
    }
};

int main()
{

    vector<int> arr = {0, 0, 1};
    // 0 1
    //  0 0 1
    // 0 1 0
    // 1 0 0 
    Solution s;

    cout << s.subsetSum(arr, 1) << endl;

    return 0;
}