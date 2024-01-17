#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> grid)
    {

        if (i == 0 && j == 0)
            return grid[i][j];
        if (i < 0 || j < 0)
            return 1e9;

        int up = grid[i][j] + solve(i - 1, j, grid);
        int left = grid[i][j] + solve(i, j - 1, grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, grid);
    }
};

int main()
{
    //   Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    // Output: 7

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution obj;
    cout << obj.minPathSum(grid) << endl;

    return 0;
}