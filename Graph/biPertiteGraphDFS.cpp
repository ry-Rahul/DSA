#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int col, vector<int> adj[], int color[])
{
    color[node] = col;

    for(auto it:adj[node]){
        // if it is not colored
        if(color[it]==-1){
            if(dfs(it, !col, adj, color)==false){
                return false;
            }
        }else if(color[it]==col){
            return false;
        }
    }

    return true;

}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here

    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    for (int i = 0; i < V; i++)
    {
        // if this node is not visited
        if (color[i] == -1)
            if (dfs(i, 0, adj, color) == false)
            {
                return false;
            }
    }
    return true;
}
int main()
{

    return 0;
}