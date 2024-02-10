#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<long long>> &dp)
    {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;

        if (dp[i][j] != -1)
            return (int)dp[i][j];

        if (s[i - 1] == t[j - 1])
        {
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);
        }

        return dp[i][j] = solve(s, t, i - 1, j, dp);
    }
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        // vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        // return solve(s,t,n,m,dp);

        // Tabulation
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        // dp print
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n][m];
    }
};
int main()
{

    string s = "babgbag";
    string t = "bag";
    Solution sol;
    cout << sol.numDistinct(s, t) << endl;

    return 0;
}