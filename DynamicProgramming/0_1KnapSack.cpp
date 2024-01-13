#include <bits/stdc++.h>
using namespace std;

int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
 
   // base case
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    // base case
    if (dp[ind][W] != -1)
        return dp[ind][W];
    

    // recursive case 
    int notTake = f(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
    
    // rerturn
    return dp[ind][W] = max(notTake, take);
}

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight)
{
    // Write your code here
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return f(n - 1, maxWeight, wt, val, dp);


    // Tabulation
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int W = wt[0]; W <= maxWeight; W++)
    {
        dp[0][W] = val[0];
    }

    for (int ind = 1; ind < n; ind++){
        for(int W = 0; W <= maxWeight; W++){
            // recursive case 
            int notTake = dp[ind - 1][W];
            int take = INT_MIN;
            if (wt[ind] <= W)
                take = val[ind] + dp[ind - 1][W - wt[ind]];
            
            dp[ind][W] = max(notTake, take);
        }
    }

    return dp[n-1][maxWeight];

}



int main()
{
//     4
// 1 2 4 5
// 5 4 8 6
    
    int n=4;
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};

    int maxWeight = 5;
    cout<<knapsack(wt, val, n, maxWeight)<<endl;

    return 0;
}