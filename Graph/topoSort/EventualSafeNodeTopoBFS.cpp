#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> indegree(V, 0);
        vector<int> RevAdj[V];
        // reverse the graph
        for (int i = 0; i < V; i++) {

            // i->it
            // it->i
            for (auto it : adj[i]) {
                indegree[i]++;
                RevAdj[it].push_back(i);
            }
        }

        // queue for storing nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safenodes;

        // traverse the graph
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safenodes.push_back(node);

            for (auto it : RevAdj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};
int main()
{
/*     Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6] */
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    Solution s;
    vector<int> ans = s.eventualSafeNodes(graph);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}