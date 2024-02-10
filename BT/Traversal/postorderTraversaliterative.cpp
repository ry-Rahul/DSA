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
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    stack<TreeNode*> st;
    st.push(root);

 

}
int main(){
  

  return 0;
}