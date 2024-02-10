#include <bits/stdc++.h>
using namespace std;

// leetCode 733
class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<vector<int>> &image, int row, int col, int delRow[], int delCol[], int newColor, int initialImg)
    {

        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == initialImg && ans[newRow][newCol] != newColor)
            {
                dfs(ans, image, newRow, newCol, delRow, delCol, newColor, initialImg);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int initialImg = image[sr][sc];
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(ans, image, sr, sc, delRow, delCol, color, initialImg);
        return ans;
    }
};
int main()
{
    // Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, color);
    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

    return 0;
}