#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> printAdjList(int n ,int m, vector<pair<int, int>> edges)
{
    vector<vector<int >> ans(n);
    for (int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    // add index to the vector
    for (int i = 0; i < n; i++){
        ans[i].insert(ans[i].begin(), i);
    }
        // 0-> 0 3 
        // 1-> 1 2 
        // 2-> 2 1 3 
        // 3-> 3 0 2 
    return ans;
}

void printGraph(vector<vector<int>> adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << adj[i][0] << "-> ";
        for (int j = 1; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<pair<int, int>> edges;
    // int arr[] = {0, 1, 2, 3};
    edges.push_back({1, 2});
    edges.push_back({0,3});
    edges.push_back({2,3});

    vector<vector<int>> adj = printAdjList(4, 3, edges);
    printGraph(adj);
        return 0;
}