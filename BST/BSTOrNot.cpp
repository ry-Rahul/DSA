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

class Solution {
public:
    bool isValid(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;

        if(root->val >= maxi || root->val <= mini){
            return false;
        }

        return (isValid(root->left,mini,root->val) && (isValid(root->right,root->val,maxi)));
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};
int main(){
  

  return 0;
}