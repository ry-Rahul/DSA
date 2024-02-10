#include <bits/stdc++.h>
using namespace std;

// Recursive approach to find the longest common subsequence of two strings s1 and s2 of length n and m respectively
int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp);

    return dp[n][m] = max(solve(s1, s2, n - 1, m, dp),
                          solve(s1, s2, n, m - 1, dp));
}

void longestCommonSubsequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    solve(s1, s2, n, m, dp);

    string ans = "";
    int len = dp[n][m];
    for (int i = 0; i < len; i++)
        ans += "$";

    int i = n;
    int j = m;
    int index = len - 1;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[index] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    cout << ans << endl;
}

int main()
{

    longestCommonSubsequence("abcde", "ace");

    return 0;
}