#include <bits/stdc++.h>
using namespace std;

// gfg detect cycle in undirected graph
bool detect(int src, vector<int> adj[], int vis[])
{

    vis[src] = 1;
    queue<pair<int, int>> q;

    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                q.push({adjacentNode, node});
                vis[adjacentNode] = 1;
            }
            else if (parent != adjacentNode)
            {
                return true;
            }
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
            if (detect(i, adj, vis) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
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

    cout << isCycle(5, adj)<<endl;


    return 0;
}