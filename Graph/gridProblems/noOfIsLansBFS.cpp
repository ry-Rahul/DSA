#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == '1')
                {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};


int main()
{

    // Input: grid = [
    //   ["1","1","0","0","0"],
    //   ["1","1","0","0","0"],
    //   ["0","0","1","0","0"],
    //   ["0","0","0","1","1"]

    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};

    vector<vector<char>> grid2 = {
        {'1', '1' ,'1', '0'},
        {'0', '1', '0', '1'},
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'}
    };
     Solution s;
    cout << s.numIslands(grid2) << endl;



    return 0;
}