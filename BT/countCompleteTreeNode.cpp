#include <bits/stdc++.h>
using namespace std;

// leetcode 222. Count Complete Tree Nodes
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getLeft(TreeNode *root)
    {

        int lh = 0;
        TreeNode *temp = root;
        while (temp)
        {
            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int getRight(TreeNode *root)
    {

        int lh = 0;
        TreeNode *temp = root;
        while (temp)
        {
            temp = temp->right;
            lh++;
        }
        return lh;
    }
    int solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lf = getLeft(root);
        int rh = getRight(root);

        if (lf == rh)
        {
            return (pow(2, lf) - 1);
        }

        return solve(root->left) + 1 + solve(root->right);
    }
    int countNodes(TreeNode *root)
    {
        return solve(root);
    }
};
int main()
{

    return 0;
}