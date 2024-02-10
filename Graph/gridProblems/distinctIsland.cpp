#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col, vector<vector<int>>& grid ,
    vector<vector<int>>& vis,vector<pair<int,int>> &vec,int row0,int col0){
        
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int n=grid.size();
        int m=grid[0].size();
        
        
        
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                vis[nRow][nCol] = 1;
                dfs(nRow,nCol,grid,vis,vec,row0,col0);
            }        
            
        }
        // time complexity: n*m*log(n*m) + n*m*4 
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                    
                }
            }
        }
        
        return st.size();
        
    }
int main(){
    
    // grid[][] = {{1, 1, 0, 1, 1},
    //         {1, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1},
    //         {1, 1, 0, 1, 1}}

    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};

    cout << countDistinctIslands(grid)<<endl;

  return 0;
}