#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;   
    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an adge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            // create an adge from v to u
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto entry : i.second)
            {
                cout << entry << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    cout << "Enter the number of Nodes ";
    int n;
    cin >> n;
    cout << "Enter the number of edges ";
    int e;
    cin >> e;
    //  4
    //  6
    //  0 1
    //  0 2
    //  1 2
    //  2 3
    //  1 3
    //  0 3
    Graph<int> g;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}
