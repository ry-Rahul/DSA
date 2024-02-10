#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        // 6 price of 1 length
        // 0 index
        // 1 length
        // N = 12 
        // iam looking to make 12 rod length with 1 length rod so price is 12*6

        return N * price[ind];
    }
    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTake = 0 + solve(ind - 1, N, price, dp);
    int rodLength = ind + 1;
    int take = INT_MIN;
    if (rodLength <= N)
        take = price[ind] + solve(ind, N - rodLength, price, dp);

    return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, n, price, dp);
}
int main()
{

    //  question is to find the maximum profit by cutting the rod and selling the pieces
    int n = 5;
    vector<int> price = {2, 5, 7, 8};
    cout << cutRod(price, n) << endl;

    return 0;
}