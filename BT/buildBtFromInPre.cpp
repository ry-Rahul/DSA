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

// int findPos(int in[], int element, int n)
// {

//     for (int i = 0; i < n; i++)
//     {
//         if (in[i] == element)
//             return i;
//     }
//     return -1;
// }

// Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
// {

//     if (index >= n || inorderStart > inorderEnd)
//     {
//         return NULL;
//     }
//     int element = pre[index++];
//     Node *root = new Node(element);

//     int pos = findPos(in, element, n);

//     root->left = solve(in, pre, index, inorderStart, pos - 1, n);
//     root->right = solve(in, pre, index, pos + 1, inorderEnd, n);

//     return root;
// }
// // n is the size of the array
// Node *buildTree(int in[], int pre[], int n)
// {
//     // Code here
//     int preOrderIndex = 0;
//     Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);

//     return ans;
// }

// inorder
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// preorder
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// postorder
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ! its by mapping the index of the element in the inorder array
void createMap(int in[], map<int, int> &indexToNode, int n)
{

    for (int i = 0; i < n; i++)
    {
        indexToNode[in[i]] = i;
    }
}

Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd,
            int n, map<int, int> &indexToNode)
{

    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);

    int pos = indexToNode[element];

    root->left = solve(in, pre, index, inorderStart, pos - 1, n, indexToNode);
    root->right = solve(in, pre, index, pos + 1, inorderEnd, n, indexToNode);

    return root;
}
// n is the size of the array
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    map<int, int> indexToNode;

    createMap(in, indexToNode, n);

    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, indexToNode);

    return ans;
}
//! end of this code
int main()
{

    // int in[] = {7, 3, 11, 1, 17, 3, 18};
    // int pre[] = {1, 3, 7, 11, 3, 17, 18};
    int in[] = {1, 2, 3, 4, 5, 2, 7};
    int pre[] = {1, 2, 3, 4, 5, 2, 7};
    int n = 7;
    Node *root = buildTree(in, pre, n);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    return 0;
}
