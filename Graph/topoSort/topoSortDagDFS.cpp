#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int>adj[],stack<int>&st){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	            
	        }
	    }
	    
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	    
	}
int main(){
  
   int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> res = topoSort(V, adj);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}