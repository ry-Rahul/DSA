#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {

        int r = q.front().first.first;
        int c = q.front().first.second;
        int step = q.front().second;

        q.pop();

        dist[r][c] = step;

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
            {
                q.push({{nrow, ncol}, step + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }

    return dist;
}
int main()
{
/* 
    Input: grid = {{0,0,0},{0,1,0},{1,0,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}} */
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{1,0,1}};
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}