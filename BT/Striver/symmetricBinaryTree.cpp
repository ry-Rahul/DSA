#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
 bool solve(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2!=NULL){
            return false;
        }
        if(root1!=NULL && root2==NULL){
            return false;
        }
        if(root1==NULL && root2==NULL){
            return true;
        }

        bool left=solve(root1->left,root2->right);
        bool right=solve(root1->right,root2->left);
        bool ans=root1->val==root2->val;
        
        return left&&right&&ans;

    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
int main(){
  

  return 0;
}