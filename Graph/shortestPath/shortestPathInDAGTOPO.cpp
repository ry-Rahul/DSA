#include <bits/stdc++.h>
using namespace std;
/*
1. Do a topological sort
2. Take a node out from the stack and relax all its edges  */

void topologicalSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            topologicalSort(it.first, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // N is the number of nodes
    // M is the number of edges

    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // find the topological sort
    stack<int> st;
    vector<int> vis(N, 0);

    // O(N+M)
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topologicalSort(i, adj, vis, st);
        }
    }

    
    // step 2 do the distance things
    vector<int> dist(N, 1e9);

    // dist of source is 0
    dist[0] = 0;

    // O(N+M)
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}
int main()
{
    //   N = 6, M = 7
    // edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
    // Output:
    // 0 2 3 6 1

    int N = 6, M = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> ans = shortestPath(N, M, edges);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}