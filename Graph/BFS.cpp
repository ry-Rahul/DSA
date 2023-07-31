#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void BFS(int src){
        queue<int> q;
        unordered_map<int,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto neighbour:adj[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto entry:i.second){
                cout<<entry<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;  
    g.addEdge(0,1,0);
    g.addEdge(0,3,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);

    g.printAdjList();
    cout << endl;
    g.BFS(0);

    
    return 0;
}