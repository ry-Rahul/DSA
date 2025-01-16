#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

// sc - O(n) + O(n)visited array + O(n)recursion stack
// tc - O(n) + O(v+2E)dfs
    void dfs(int node, vector<int> adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {


        // print isConnected
        int v=isConnected.size();
        
        vector<int> adjLst[v];
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLst[i].push_back(j);
                    adjLst[j].push_back(i);
                }
            }
        }

        // print adjLst
        for(int i=0; i<v; i++){
            cout<<i<<"->";
            for(auto it:adjLst[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        

        int cnt=0;
        vector<int> vis(v,0);
        for(int i=0;i<v; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLst,vis);
            }
        }

        return cnt;
    }
};
int main(){

    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution obj;

       vector<vector<int>> grid2 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };
    cout<<obj.findCircleNum(grid2);
  

  return 0;
}