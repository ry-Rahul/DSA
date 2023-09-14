#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &heights, vector<int> &dp)
{
    // Write your code here.
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int left = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // Tabulation approach
    /*

    vector<int> dp(n+1,0);
    dp[0] = 0;

    for(int i = 1; i<n; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2] + abs(heights[i]-heights[i-2]);

        dp[i] = min(left,right);
    }

    return dp[n - 1];

    */

    // Optiaml Tabulation approach
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(left, right);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// Frog jump for i+1 , i+2 , i+3 , i+4 ..... i+k_______________________________________
int solve2(int ind, vector<int> &heights, vector<int> &dp, int k)
{
    // Write your code here.  time complexity is O(n) * k
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int minStep = INT_MAX;
    for (int i = 1; i < k; i++)
    {
        if (ind - i > 0)
        {
            int jump = solve2(ind - i, heights, dp,k) + abs(heights[ind] - heights[ind - i]);
            minStep = min(minStep, jump);
        }
    }
    return dp[ind] = minStep;
}


// Tabulation approach
    /*

    vector<int> dp(n+1,0);
    dp[0] = 0;

    for(int i = 1; i<n; i++){
        minStep = INT_MAX;
        for(int j = 1; j<=k; j++){
            if(i-j>=0){
                int jump = dp[i-j] + abs(heights[i]-heights[i-j]);
                minStep = min(minStep, jump);
            }
        }

        dp[i] = minStep;
    }

    return dp[n - 1];

    */

int main()
{

    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(n, heights) << endl;

    return 0;
}
