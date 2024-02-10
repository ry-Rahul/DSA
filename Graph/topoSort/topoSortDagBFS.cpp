#include <bits/stdc++.h>
using namespace std;

// topo sort using bfs for DAG  or (kahn's algorithm)
// 1. store indegree of all nodes in an array
// 2. push all nodes with indegree 0 in a queue
// 3. pop a node from queue and print it and reduce indegree of all its neighbours by 1
// 4. if indegree of any neighbour becomes 0 push it in queue
// 5. repeat 3 and 4 till queue is empty


// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // find indegree of all nodes
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    // push all nodes with indegree 0 in queue
    for (int i = 0; i < V; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return topo;
}
int main()
{

    return 0;
}