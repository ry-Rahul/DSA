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
int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    int ans = max(lheight, rheight) + 1;

    return ans;
}

// its time complexity is O(n^2)
int diameterOfBinaryTree(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    int ans = max(op3, (max(op1, op2)));

    return ans;
}

// Its time complexity is O(n)
pair<int, int> fastDiameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op3, (max(op1, op2)));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int main()
{
    Node *root = NULL;
    return 0;
}