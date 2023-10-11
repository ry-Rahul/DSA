#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        bool flag = false;

        // Fill first row
        for (int i = 0; i < n; i++)
        {

            if (flag || obstacleGrid[0][i] == 1)
            {
                dp[0][i] = 0;
                flag = true;
            }
            else
            {
                dp[0][i] = 1;
            }
        }

        // Fill first column
        flag = false;
        for (int i = 0; i < m; i++)
        {

            if (flag || obstacleGrid[i][0] == 1)
            {
                dp[i][0] = 0;
                flag = true;
            }
            else
            {
                dp[i][0] = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        // print dp array
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

// unique paths
int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &paths)
{
    if (i >= 0 && j >= 0 && paths[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp, paths);
    int left = solve(i, j - 1, dp, paths);

    return dp[i][j] = up + left;
}

int uniquePaths(vector<vector<int>> &paths)
{

    int m = paths.size();
    int n = paths[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp, paths);
}

int tabulationApproach(vector<vector<int>> &path){
    int m = path.size();
    int n = path[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for(int i = 0 ; i<m; i++){
        for(int j = 0 ; j<n; j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }else if(path[i][j]==1){
                dp[i][j]=0;
            }
            else{
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if(j>0)
                    left = dp[i][j-1];
                 dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    //   Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    // Output: 2

    vector<vector<int>> obstacleGrid = {{1}};
    // vector<vector<int>> obstacleGrid = {{0, 0, 0, 0},
    //                                     {1, 0, 1, 0},
    //                                     {0, 0, 0, 0}};
    Solution s;
    // cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << uniquePaths(obstacleGrid) << endl;
    // cout<<tabulationApproach(obstacleGrid)<<endl;

    return 0;
}
