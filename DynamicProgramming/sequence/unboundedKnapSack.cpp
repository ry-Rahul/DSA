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

    return 0;
}