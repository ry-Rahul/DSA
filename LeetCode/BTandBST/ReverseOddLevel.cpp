#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

   void solve(TreeNode *root1,TreeNode *root2,int height){
       if(root1==NULL && root2==NULL){
           return;
       }
       if(height%2==0){
           swap(root1->val,root2->val);
       }
       solve(root1->left,root2->right,height+1);
       solve(root1->right,root2->left,height+1);

   }

    TreeNode* reverseOddLevels(TreeNode* root) {
        
        int height = 0;
        solve(root->left,root->right,height);

        return root;
    }
};

void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void levelOrder(TreeNode *root){
    if(root==NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->val<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}


int main()
{
    TreeNode *root = NULL;
        Solution s;

    root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);
    
    levelOrder(root);
    cout << endl
         << "--------------------------------"<<endl;
    TreeNode *ans = s.reverseOddLevels(root);
    
    levelOrder(ans);

  

  return 0;
}