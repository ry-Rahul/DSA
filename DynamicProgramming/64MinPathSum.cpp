#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        // fill 1sr row
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        // fill 1st column
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // print the dp array
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[m - 1][n - 1];
    }
};
int main()
{

    //     Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    // Output: 7

    vector<vector<int>> grid = {{1, 3, 5}, {2, 1, 2}, {4, 3, 1}};
    Solution obj;
    cout << obj.minPathSum(grid)<<endl;

    return 0;
}