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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    stack<TreeNode*> st;
    st.push(root);

    // N L R
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
    }

    return ans;

}
int main(){

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(4);
    //                1
    //              /   \
    //             3     2
    //                  / \
    //                 5   4
    vector<int> ans=preorderTraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
  

  return 0;
}