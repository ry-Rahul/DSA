#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cntFresh = 0;


        int vis[n][m];

        queue<pair<pair<int,int>,int>> q;

        // grid[i][j]=2 means rotten
        // grid[i][j]=1 means fresh
        // grid[i][j]=0 means empty
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        int tm=0;
        int drow[]={-1,0,+1,0};
        int cnt=0;
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;

            tm=max(tm,t);

            q.pop();

            for(int i=0; i<4 ; i++){     
                    int nrow=r+drow[i];
                    int ncol=c+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                        q.push({{nrow,ncol},t+1});
                        vis[nrow][ncol]=2;
                        cnt++;
                    }
            }
        }


// check all fresh oranges are rotten or not 
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
               if(vis[i][j]!=2 && grid[i][j]==1){
                   return -1;
               }
            }
        }

        return tm;
 
    }
};
int main(){

    // vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> grid;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n ; i++){
        vector<int> v;
        for(int j=0; j<m ; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        grid.push_back(v);
    }
    Solution obj;
    cout<<obj.orangesRotting(grid);
  

  return 0;
}