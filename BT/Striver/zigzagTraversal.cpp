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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        bool leftToRight = true;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = temp->val;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }

        return res; 
    }
};

int main()
{

    return 0;
}