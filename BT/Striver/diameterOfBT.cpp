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
int maxi = 0;
int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

void solve(TreeNode *root)
{
    if (root == NULL)
        return;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    maxi = max(maxi, (lh + rh));

    solve(root->left);
    solve(root->right);
}
int diameterOfBinaryTree(TreeNode *root)
{
    solve(root);
    return maxi;
} */

// approach 2___________________________________________________________
int maxi = 0;
int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    maxi = max(maxi, (left + right));

    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    heightOfTree(root);
    return maxi;
}
int main()
{

    return 0;
}