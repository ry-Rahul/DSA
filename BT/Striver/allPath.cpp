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

void solve(TreeNode *root, vector<string> &ans, string &str)
{
    if (root == NULL)
    {
        return;
    }

    str += to_string(root->val);
    str += "->";

    if (root->left == NULL && root->right == NULL)
    {
        str.pop_back();
        str.pop_back();
        ans.push_back(str);
    }

    solve(root->left, ans, str);
    solve(root->right, ans, str);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string str = "";
    solve(root, ans, str);
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);

    vector<string> ans = binaryTreePaths(root);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    

    return 0;
}