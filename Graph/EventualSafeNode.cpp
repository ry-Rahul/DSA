#include <bits/stdc++.h>
using namespace std;

// leetcode 802
// safe node is a node from which we can reach a terminal node
// terminal node is a node from which we can't go anywhere
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

/* 
any node that has a cycle can't be a safe node
any one lead to a node that has a cycle can't be a safe node
 */


bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis, check)==true){
                check[node] = 0;
                return true;
            } 
        }
        // if the node is previously visited 
        // ans pathvisted bhi hai toh cycle hai
        else if (pathVis[it])
        {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> check(n,0);
    vector<int> safeNodes;

    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfsCheck(i,graph,vis,pathVis,check);
        }
    }

    for(int i=0;i<n;i++){
        if(check[i]==1) safeNodes.push_back(i);
    }

    return safeNodes;
}
int main()
{
    //   Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    // Output: [4]

    // [[1,2],[2,3],[5],[0],[5],[],[]]

    // vector<vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = eventualSafeNodes(graph);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}