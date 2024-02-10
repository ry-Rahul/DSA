#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse in its neighbour
        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delCol = -1; delCol <= 1; delCol++)
            {
                if (delRow == 0 && delCol == 0)
                {
                    continue;
                }
                int newRow = row + delRow;
                int newCol = col + delCol;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == '1')
                {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}
// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                cnt++;
                bfs(row, col, grid, vis);
            }
        }
    }

    return cnt;
}
int main()
{

    // grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};
    vector<vector<char>> grid = {{'0', '1', '1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '1', '0', '1', '0'}};
    cout << numIslands(grid) << endl;

    return 0;
}