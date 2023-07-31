#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// fastIsBalanced function time complexity is O(n)
pair<bool, int> isBalancedFast(Node *root)
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
bool isIdentical(Node *root1, Node *root2)
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
pair<bool, int> isSumTreeFast(Node *root)
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
bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

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