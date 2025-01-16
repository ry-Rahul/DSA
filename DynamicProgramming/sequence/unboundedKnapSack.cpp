#include <bits/stdc++.h>
using namespace std;

// infinite supply
// unbounded knapsack

int solve(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[ind] <= w)
        {
            return ((int)(w / wt[ind])) * val[ind];
        }
        return 0;
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];

    // notake
    int notTake = 0 + solve(ind - 1, w, wt, val, dp);
    int take = 0;
    if (wt[ind] <= w)
        int take = val[ind] + solve(ind, w - wt[ind], wt, val, dp);

    return dp[ind][w] = max(take, notTake);
}

int main()
{

    /* 'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27 */
    int n = 3;
    int w = 10;
    vector<int> val = {5, 11, 13};
    vector<int> wt = {2, 4, 6};
    
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    cout << solve(n - 1, w, wt, val, dp) << endl;


    return 0;
}