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
void rightView(TreeNode *root, vector<int> &v, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (v.size() == level)
    {
        v.push_back(root->val);
    }
    rightView(root->right, v, level + 1);
    rightView(root->left, v, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> v;
    rightView(root, v, 0);
    return v;
}
int main()
{

    return 0;
}