#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// fastIsBalanced function time complexity is O(n)
pair<bool, int> isBalancedFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

// todo : check if two trees are identical or not
bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// todo : check if a tree is sum tree or not
pair<bool, int> isSumTreeFast(node *root)
{

    // todo base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // todo check leaf nodes condition
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    // todo recursive case
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == leftSum + rightSum;

    pair<bool, int> ans;

    if (isLeftSumTree && isRightSumTree && condn)
    {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
// todo : check if a tree is sum tree or not
bool isSumTree(node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);

    // balancedFast function
    pair<bool, int> ans = isBalancedFast(root);
    if (ans.first)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}