#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solve(i - 1, j, dp);
        int left = solve(i, j - 1, dp);

        return dp[i][j] = up + left;

        /*  if (i >= 0 && j >= 0 && paths[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp, paths);
    int left = solve(i, j - 1, dp, paths);

    return dp[i][j] = up + left; */
    }

    int uniquePaths(int m, int n)
    {

        // why dp[m][n] is size is declared
        // because  max value of i can be m-1 and max value of j can be n-1
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);

        int dp[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int spaceOptimizaiton(int m, int n)
    {
        int prev[n];
        memset(prev, 0, sizeof(prev));
        for (int i = 0; i < m; i++)
        {
            int temp[n];
            memset(temp, 0, sizeof(temp));
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    temp[j] = 1;
                else
                    temp[j] = prev[j] + temp[j - 1];
            }
            // prev = temp;
            memcpy(prev, temp, sizeof(temp));
        }
        return prev[n - 1];
    }
};

int main()
{

    //     Input: m = 3, n = 7
    //     Output: 28

    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    cout << s.spaceOptimizaiton(3, 7) << endl;

    return 0;
}