#include <bits/stdc++.h>
using namespace std;
// 322 leetcode coin change


// min number of coins to make amount using coins
class Solution
{
public:
    int solve(int ind, vector<int> &coins, int target, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (target % coins[ind] == 0)
            {
                return target / coins[ind];
                
            }
            else
                return 1e8;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = 0 + solve(ind - 1, coins, target, dp);
        int take = 1e8;
        if (coins[ind] <= target)
            take = 1 + solve(ind, coins, target - coins[ind], dp);

        return dp[ind][target] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();

        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // return solve(n - 1, coins, amount,dp);

        // Tabulation
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        /* if (ind == 0)
        {
            if (target % coins[ind] == 0)
            {
                return target / coins[ind];
                
            }
            else
                return 1e8;
        } */
        for (int T = 0; T <= amount; T++)
        {
            if (T % coins[0] == 0)
                dp[0][T] = T / coins[0];
            else
                dp[0][T] = 1e8;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= amount; T++)
            {
                int notTake = dp[ind - 1][T];
                int take = 1e8;
                if (coins[ind] <= T)
                    take = 1 + dp[ind][T - coins[ind]];

                dp[ind][T] = min(take, notTake);
            }
        }

        return dp[n - 1][amount] == 1e8 ? -1 : dp[n - 1][amount];
    }
};

int main()
{

    vector<int> coins = {1, 2, 5,6,9};
    int amount = 11;
    Solution s;
    cout << s.coinChange(coins, amount) << endl;

    return 0;
}


// 9-5
// 8-4
// 7-3
// 6-2
// 3-1
// 1-0


