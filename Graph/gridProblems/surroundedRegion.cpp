#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void printBoard(vector<vector<char>> &board)
    {
        for (auto it : board)
        {
            for (auto it2 : it)
            {
                cout << it2 << " ";
            }
            cout << endl;
        }
    }

    void printBoard(vector<vector<int>> &board)
    {
        for (auto it : board)
        {
            for (auto it2 : it)
            {
                cout << it2 << " ";
            }
            cout << endl;
        }
    }

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int dRow[], int dCol[])
    {

        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 'O')
            {
                dfs(nRow, nCol, vis, grid, dRow, dCol);
            }
        }
    }
    
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // rows traversal
        for (int i = 0; i < m; i++){
            // first row
            if (!vis[0][i] && board[0][i] == 'O'){
                dfs(0, i, vis, board, dRow, dCol);
            }

            // last row
            if (!vis[n - 1][i] && board[n - 1][i] == 'O'){
                dfs(n - 1, i, vis, board, dRow, dCol);
            }
        }

        // printBoard(board);
        // columns traversal
        for (int i = 0; i < n; i++)
        {
            // first col
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, dRow, dCol);

            // last col
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board, dRow, dCol);
        }

        printBoard(board);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && board[i][j] == 'O'){
                    vis[i][j] = 1;
                    board[i][j] = 'X';
                }
            }
        }

        cout << endl;
        printBoard(board);
    }
};
int main()
{

    // Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    // Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // [["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
    vector<vector<char>> board = {{'X', 'O', 'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'O', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution obj;
    obj.solve(board);
    // for(auto it:board){
    //     for(auto it2:it){
    //         cout<<it2<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}