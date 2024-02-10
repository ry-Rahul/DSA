#include <bits/stdc++.h>
using namespace std;

/* Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned. */

vector<int> topoSort(int n, vector<int>adj[]){
        vector<int> indegree(n,0);
        vector<int> topo;
        
        for(int i=0;i<n; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return topo;
        
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i=0; i<N-1; i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            
            int len=min(s1.size(), s2.size());
            for(int i=0; i<len ;i++){
                if(s1[i]!=s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        
        
        vector<int> topo=topoSort(K,adj);
        string ans="";
        for(auto it:topo){
            ans+=char(it+'a');
        }
        
        return ans;
    }
int main(){

    int n=5;
    int k=4;
    // n is the number of words in the dictionary
    // k is the number of characters in the dictionary
    string dict[]={"baa","abcd","abca","cab","cad"};
    cout<<findOrder(dict,n,k)<<endl;
  
  return 0;
}