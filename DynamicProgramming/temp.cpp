#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &path, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && path[i][j] == 1)
            return 0;
        if (i == 0 && j == 0){
            return 1;
        }
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solve(i - 1, j, path, dp);
        int left = solve(i, j - 1, path, dp);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, obstacleGrid, dp);
    }
};

int main()
{

    Solution s;
    vector<vector<int>> obstacleGrid = {{1}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}