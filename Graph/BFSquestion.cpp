#include <bits/stdc++.h>
using namespace std;

void preparedAdjList(unordered_map<int,list<int>> &adj,vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for(auto neighbour:adj[frontNode]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
}
vector<int> BFS(int vertex,vector<pair<int,int>> edges){
    // first make adjacency list
    unordered_map<int,list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    preparedAdjList(adj,edges);

    // traverse all components of graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj, visited, ans, i);
        }
    }
    return ans;
}



int main()
{
    // 4 nodes and 4 edges
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 3});
    edges.push_back({1, 2});
    edges.push_back({2, 3});

    vector<int> v = BFS(4, edges);
    for (auto i : v)
    {
        cout << i << " ";
    }
   
    return 0;
}