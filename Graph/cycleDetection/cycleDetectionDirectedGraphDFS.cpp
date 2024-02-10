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

    int n = 6;
    vector<int> adj[n];

    adj[0].push_back(1);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(3);
    
    cout << isCyclic(n, adj) << endl;

    return 0;
}