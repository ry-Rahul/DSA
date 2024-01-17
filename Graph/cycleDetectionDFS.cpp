#include <bits/stdc++.h>
using namespace std;
 bool dfs(int node, int parent,vector<int> adj[],int vis[]){
        vis[node]=1;
        
        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode,node,adj,vis)==true)return true;
            }else if(adjacentNode!=parent){
                return true;
            }
        }
        return false;
       
   }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[5]={0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
int main(){

    // adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
    // 0---1---2
    //     |   |
    //     4---3

    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(1);
    adj[4].push_back(3);

    cout<<isCycle(5,adj)<<endl;

  

  return 0;
}