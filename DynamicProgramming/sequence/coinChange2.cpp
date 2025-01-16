#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // how many ways to make amount using coins
    int solve(int ind, int target, vector<int> coins, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            return target % coins[ind] == 0;
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        int notTake = solve(ind - 1, target, coins, dp);
        int take = 0;
        if (target >= coins[ind])
        {
            take = solve(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = take + notTake;
    }
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        int target = amount;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(n - 1, amount, coins, dp);

        // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // for (int i = 0; i < n; i++) {
        //     dp[i][0] = 1;
        // }
    }
};
int main()
{

    // vector<int> coins = {1, 2, 5};
    vector<int> coins = {3,5,10};
    int amount = 10;
    // ans 4
    Solution s;
    cout << s.change(amount, coins);

    return 0;
}