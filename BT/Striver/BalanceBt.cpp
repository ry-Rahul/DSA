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

// approach 1
/*
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}


bool isBalanced(TreeNode* root) {

        if(root==NULL){
            return true;
        }

        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)<=1)
            return false;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        return left&&right;
} */

// approach 2
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    if (lh == -1)
        return -1;
    int rh = height(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}


bool isBalanced(TreeNode *root)
{
    return height(root) != -1;
}
int main()
{

    return 0;
}