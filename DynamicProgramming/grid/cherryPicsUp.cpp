#include <bits/stdc++.h>
using namespace std;
/* We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.
They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect. */

// fixed starting point
// variable ending point
// then start from fixed point and go to the variable point

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // explore all the path simultaneously
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];

            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}


int maximumChoclate(int r, int c, vector<vector<int>> &grid)
{

    // why we pass r not r-1
    // because we are passing the row number not the index

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c - 1, r, c, grid, dp);
}
int main()
{

    int r = 3, c = 4;
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};
    cout << maximumChoclate(r, c, grid) << endl;
    return 0;
}