#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};
vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* node=root;

    if(root==NULL){
        return ans;
    }
    //             1
    //           /   \
    //          2     3
    //         / \
    //        4   5
    //           / \
    //          6   7
    while(true){

        //  L N R
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()){ 
                break;
            }
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }

    return ans;
}
int main(){

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
  
    vector<int> ans=inorderTraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
  

  return 0;
}