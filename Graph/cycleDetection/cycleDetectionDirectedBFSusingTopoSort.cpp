#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    
    if (cnt == V)
    {
        return false;
    }

    return true;
}

int main()
{
    int V, E;
    vector<int> adj[]={{1},{2},{3},{3}};

    cout << isCyclic(4, adj) << endl;

    return 0;
}