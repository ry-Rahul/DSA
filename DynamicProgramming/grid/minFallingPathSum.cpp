#include <bits/stdc++.h>
using namespace std;

// eetcode 931

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {

        if (j < 0 || j >= mat[0].size())
            return 1e8;
        if (i == 0)
            return mat[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int u = mat[i][j] + solve(i - 1, j, mat, dp);
        int ld = mat[i][j] + solve(i - 1, j - 1, mat, dp);
        int rd = mat[i][j] + solve(i - 1, j + 1, mat, dp);

        return dp[i][j] = min(u, min(ld, rd));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e8;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int j = 0; j < n; j++)
        {
            mini = min(mini, solve(m - 1, j, matrix, dp));
        }

        return mini;
    }
};

int tabulationMethod(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int mini = 1e8;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // from base case
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int right = matrix[i][j];
            if (j+1 < n )
                right += dp[i - 1][j + 1];
            else
                right += 1e8;

            int left = matrix[i][j];
            if (j - 1 >= 0)
                left += dp[i - 1][j - 1];
            else
                left += 1e8;

            dp[i][j] = min(left, min(right, up));
        }
    }

    for (int j = 0; j < n; j++)
    {
        mini = min(mini, dp[m - 1][j]);
    }

    return mini;
}
int main()
{

    vector<vector<int>> matrix = {{1, 3, 1}, 
                                  {6, 5, 1},
                                  {7, 8, 1}};
    Solution s;
    cout << s.minFallingPathSum(matrix) << endl;
    cout << tabulationMethod(matrix) << endl;

    return 0;
}