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

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return root;
    while (root != NULL && root->val != val)
    {
        root = val < root->val ? root->left : root->right;
    }

    return root;
}

int main()
{

    return 0;
}