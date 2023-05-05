#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
    };

 int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
              return 0;
          }

          if(root->left!=NULL && root->left->right==NULL&& root->left->left == NULL){
                return root->left->data + sumOfLeftLeaves(root->right);
          }
          return sumOfLeftLeaves(root->left) +sumOfLeftLeaves(root->right);
          
    }

// queue method
int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
              return 0;
          }
          
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL && node->left->left==NULL && node->left->right==NULL){
                sum+=node->left->data;
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        return sum;
    }


int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);



  return 0;
}