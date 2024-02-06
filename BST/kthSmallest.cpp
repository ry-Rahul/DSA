#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void solve(TreeNode *root, int &i, int k, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    solve(root->left, i, k, ans);
    i++;
    if (i == k)
        ans = root->val;

    solve(root->right, i, k, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans = 0, i = 0;
    solve(root, i, k, ans);
    return ans;
}
int main()
{

    return 0;
}