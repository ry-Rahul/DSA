#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* int solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
            return 1 + solve(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = max(solve(s1, s2, i - 1, j, dp),
                              solve(s1, s2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(s1, s2, n - 1, m - 1, dp);
    } */

    // for tabulation we shift the base condition to the initialization of the dp array
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {

        if (i == 0 || j == 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i - 1] == s2[j - 1])
            return 1 + solve(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = max(solve(s1, s2, i - 1, j, dp),
                              solve(s1, s2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s1, s2, n, m, dp);

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int i=0; i<=m; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                 else   dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
            }
        
        }

        return dp[n][m];
        }
};
int main()
{

    Solution s;
    cout << s.longestCommonSubsequence("abcde", "ace") << endl;

    return 0;
}