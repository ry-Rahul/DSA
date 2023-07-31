#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);

// har connected node k liye recursice calll
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFristSearch(int v,int E,vector<pair<int,int>> edges){

    // prepare adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<E;i++){
         int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
//     9 7
// 0 1
// 0 2
// 0 5
// 3 6
// 7 4
// 4 8
// 7 8
    edges.push_back({0, 1});
    edges.push_back({0,2});
    edges.push_back({0,5});
    edges.push_back({3,6});
    edges.push_back({7,4});
    edges.push_back({4,8});
    edges.push_back({7,8});

    vector<vector<int>> ans = depthFristSearch(9, 7, edges);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " "; 
        }
        cout << endl;
    }
  

  return 0;
}