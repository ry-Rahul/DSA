

#include<bits/stdc++.h>
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
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m - 1][n - 1];
    }
};


// Recursive solution
int solveRec(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    int up = grid[i][j] + solveRec(i - 1, j, grid);
    int left = grid[i][j] + solveRec(i, j - 1, grid);

    return min(up, left);
}

// Dp solution
int solveDp(int i, int j , vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = grid[i][j] + solveDp(i-1, j, grid, dp);
    int left = grid[i][j] + solveDp(i, j-1, grid, dp);

    return dp[i][j] = min(up, left);
}

// Tabulation solution
int minSumPathTabulation(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i<m; i++){
        
        for(int j = 0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                int up = grid[i][j];
                if (i > 0) up +=dp[i-1][j];
                else up += 1e9;

                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
        return dp[m-1][n-1]; 
}

int minSumPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveRec(m - 1, n - 1, grid);
    // return solveDp(m - 1, n - 1, grid, dp);
}



int main()
{

    //     Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    // Output: 7

    // vector<vector<int>> grid = {{1, 3, 5}, {2, 1, 2}, {4, 3, 1}};
    vector<vector<int>> grid = {{1, 3, 1}, 
                                {1, 5, 1},
                                {4, 2, 1}};
    Solution obj;
    // cout << obj.minPathSum(grid) << endl;
    cout << minSumPath(grid) << endl;
    // cout << minSumPathTabulation(grid) << endl;

    return 0;
}