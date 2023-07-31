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

int main()
{
    Node *root = NULL;
    Node* node1 = new Node(5);
    root = node1;
    root->right = new Node(2);

    int ans = heightOfTree(root);
    cout << ans;

    return 0;
}