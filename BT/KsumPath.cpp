#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
  public:
    void solve(Node *root,int k,int &count,vector<int>path){
        if(root==NULL){
            return;
        }
        path.push_back(root->data);
        
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        
        int size=path.size();
        int sum=0;
        
        for(int i=size-1; i>=0; i--){
         
            sum+=path[i];
            
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        int count =0;
        vector<int> path;
        solve(root,k,count,path);
        
        return count;
    }
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);


    int k=3;
    // cin>>k;
    Solution obj;
    cout<<obj.sumK(root,k)<<endl;
    return 0;
    
}
