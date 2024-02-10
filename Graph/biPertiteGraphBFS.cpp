#include <bits/stdc++.h>
using namespace std;

bool check(int start, int V, vector<int> adj[], int col[])
{
    queue<int> q;
    q.push(start);

    col[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {

            // if it is not colored
            if (col[it] == -1)
            {
                col[it] = !col[node];
                q.push(it);
            }
            else if (col[it] == col[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here

    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
            if (check(i, V, adj, color) == false)
            {
                return false;
            }
    }
    return true;
}
int main()
{

    vector<int> adj[4];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    cout << isBipartite(4, adj) << endl;

    return 0;
}