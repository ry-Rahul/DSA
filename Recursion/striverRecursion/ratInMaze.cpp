#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(4^(n*m))
void solve(int i,int j,vector<vector<int>>&m,int n,vector<string>&ans,string move,vector<vector<int>>&vis){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }

    // downward
    if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
        vis[i][j]=1;
        solve(i+1,j,m,n,ans,move+"D",vis);
        vis[i][j]=0;
    }

    // left
    if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
        vis[i][j]=1;
        solve(i,j-1,m,n,ans,move+"L",vis);
        vis[i][j]=0;
    }

    // right
    if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
        vis[i][j]=1;
        solve(i,j+1,m,n,ans,move+"R",vis);
        vis[i][j]=0;
    }

    // upward
    if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
        vis[i][j]=1;
        solve(i-1,j,m,n,ans,move+"U",vis);
        vis[i][j]=0;
    }

}

vector<string> findPath(vector<vector<int>>&m,int n){
    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    if(m[0][0]==1){
        solve(0,0,m,n,ans,"",vis);
    }
    return ans;
}
int main(){

    vector<vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = findPath(m,4);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
  

  return 0;
}