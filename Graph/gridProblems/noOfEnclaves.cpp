#include <bits/stdc++.h>
using namespace std;

// leetcode 1020

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<int>> &grid, int dRow[], int dCol[])
    {

        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                dfs(nRow, nCol, vis, grid, dRow, dCol);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // rows traversal
        for (int i = 0; i < m; i++)
        {

            // first row
            if (!vis[0][i] && board[0][i] == 1)
            {
                dfs(0, i, vis, board, dRow, dCol);
            }

            // last row
            if (!vis[n - 1][i] && board[n - 1][i] == 1)
            {
                dfs(n - 1, i, vis, board, dRow, dCol);
            }
        }

        // printBoard(board);

        // columns traversal
        for (int i = 0; i < n; i++)
        {

            // first col
            if (!vis[i][0] && board[i][0] == 1)
            {
                dfs(i, 0, vis, board, dRow, dCol);
            }

            // last col
            if (!vis[i][m - 1] && board[i][m - 1] == 1)
            {
                dfs(i, m - 1, vis, board, dRow, dCol);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 1)
                {
                    vis[i][j] = 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{

    // Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    // vector<vector<int>> grid = {{0, 1, 1, 0},
    //                             {0, 0, 1, 0},
    //                             {0, 0, 1, 0},
    //                             {0, 0, 0, 0}};

    // [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};
    Solution s;
    cout << s.numEnclaves(grid)<<endl;

    return 0;
}