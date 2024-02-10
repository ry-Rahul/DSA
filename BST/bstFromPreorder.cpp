#include <bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* bstFromPreorder(vector<int>& preorder, int &i, int bound){
    if(i == preorder.size() || preorder[i] > bound){
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = bstFromPreorder(preorder, i, root->val);
    root->right = bstFromPreorder(preorder, i, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder){
    int i = 0; 
    return bstFromPreorder(preorder, i, INT_MAX);
}
int main(){
  

  return 0;
}