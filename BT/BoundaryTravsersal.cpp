#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// !traverse left Node
void traverseLeft(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}
// ! traverse leaf Node
void traverseLeaf(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
// !tarverse right Node
void traverseRight(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aate time store kr lega
    ans.push_back(root->data);
}
// !function for boundary traversal
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part pritn/store
    traverseLeft(root->left, ans);

    // traverse Leaf Nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(8);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right->left = new Node(9);

    vector<int> ans = boundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // inorder(root);
    // levelOrderTraversal(root);

    return 0;
}