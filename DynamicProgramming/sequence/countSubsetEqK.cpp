#include <bits/stdc++.h>
using namespace std;

// count number of subset with sum equal to k
class Solution
{
public:
    int solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (sum == 0)
            return 1;
        if (ind == 0)
            return sum == nums[0];
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

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

        // Tabulation
        // vector<vector<int>> dp(n , vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        if (nums[0] <= k)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= k; sum++)
            {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (sum >= nums[i])
                    take = dp[i - 1][sum - nums[i]];

                dp[i][sum] = take + notTake;
            }
        }

        // return dp[n - 1][k];
    }
};

int main()
{

    vector<int> arr = {3, 2, 4, 5, 1};
    Solution s;

    cout << s.subsetSum(arr, 5) << endl;

    return 0;
}