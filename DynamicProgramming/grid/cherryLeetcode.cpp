#include <bits/stdc++.h>
using namespace std;
/* You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected. */

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i==0 && j==0){
            return grid[i][j];
        }
        if(j<0 || i<0 ||  grid[i][j]==-1){
            return -1e8;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if(grid[i][j]==1){
            grid[i][j]=0;
            return dp[i][j]=1+solve(i,j,grid,dp);
        }   

        int down = solve(i - 1, j, grid, dp);
        int right = solve(i, j - 1, grid, dp);

        if(down<0 && right<0){
            return dp[i][j]=-1e8;
        }

        return dp[i][j] = grid[i][j] + max(down, right);
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return max(0, solve(n - 1, n - 1, grid, dp));
       
    }
};
int main()
{
    // Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
    // Output: 5
    vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    Solution obj;
    cout << obj.cherryPickup(grid) << endl;

    return 0;
}