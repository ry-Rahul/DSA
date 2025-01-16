#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<int> adj[], int vis[])
{
    vis[node] = 1;

    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, adj, vis) == true)
                return true;
        }
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    int vis[5] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    int t;
    cin >> t;
    while(t--){
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCycle(V, adj) << endl;
    }



    return 0;
}