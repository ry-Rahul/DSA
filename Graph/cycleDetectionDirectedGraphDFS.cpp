#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        // when the path is not visited
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis) == true)
            {
                return true;
            }
        }
        // if path has been prev visited
        // but is not visited on the same path
        else if (pathVis[it])
        {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    return 0;
}