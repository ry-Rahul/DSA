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
    int  height(TreeNode* root,int &maxSum){
        if(root==NULL) return 0;

        int leftSum=max(0,height(root->left,maxSum));
        int rightSum=max(0,height(root->right,maxSum));

        maxSum=max(maxSum,root->val+leftSum+rightSum);

        return root->val+(max(leftSum,rightSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        height(root,maxSum);
        return maxSum;
    }
};
int main(){
  

  return 0;
}