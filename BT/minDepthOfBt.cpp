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
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int lh = root->left != NULL ? height(root->left) : INT_MAX;
    int rh = root->right != NULL ? height(root->right) : INT_MAX;

    return min(lh, rh) + 1;
}
int minDepth(TreeNode *root)
{
    int ht = height(root);

    return ht;
}
int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);

    return 0;
}