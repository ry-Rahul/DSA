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
        left = NULL;
        right = NULL;
    }
};
// !kth smallest element in BST___________________________
class Solution
{
public:
    int ans = 0;
    void solve(TreeNode *root, int &i, int k)
    {
        if (root == NULL)
        {
            return;
        }

        // left
        solve(root->left, i, k);

        // node value
        i++;
        if (i == k)
            ans = root->val;
        // right subtree
        solve(root->right, i, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int i = 0;
        solve(root, i, k);
        return ans;
    }
};
// !main____________________________________

int main()
{

    return 0;
}