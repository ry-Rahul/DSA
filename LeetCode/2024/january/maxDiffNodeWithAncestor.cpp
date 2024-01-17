#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // BRUTE FORCE APPROACH____________________________________________________
    void findMaxUtil(TreeNode *root, TreeNode *child, int &maxDiff)
    {
        if (root == NULL || child == NULL)
        {
            return;
        }
        maxDiff = max(maxDiff, abs((root->val) - (child->val)));

        findMaxUtil(root, child->left, maxDiff);
        findMaxUtil(root, child->right, maxDiff);
    }
    void findMaxDiff(TreeNode *root, int &maxDiff)
    {
        if (root == NULL)
        {
            return;
        }

        findMaxUtil(root, root->left, maxDiff);
        findMaxUtil(root, root->right, maxDiff);

        findMaxDiff(root->left, maxDiff);
        findMaxDiff(root->right, maxDiff);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        int maxDiff = -1;
        findMaxDiff(root, maxDiff);
        return maxDiff;
    }
    // BRUTE FORCE APPROACH____________________________________________________
};

//  optimized approach____________________________________________________
int findMaxDiff(TreeNode *root, int maxi, int mini)
{
    if (root == NULL)
    {
        return abs(maxi - mini);
    }

    maxi = max(maxi, root->val);
    mini = min(mini, root->val);
    int l = findMaxDiff(root->left, maxi, mini);
    int r = findMaxDiff(root->right, maxi, mini);

    return max(l, r);
}
int maxAncestorDiff(TreeNode *root)
{

    int ans = findMaxDiff(root, root->val, root->val);
    return ans;
}

// optimized approach___________________________________________
int main()
{

    return 0;
}