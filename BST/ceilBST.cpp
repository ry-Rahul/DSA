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

int findCeil(TreeNode *root, int key)
{

    int ceil = -1;

    while (root != NULL)
    {
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }
        else if (root->val < key)
        {
            root = root->right;
        }
        else if (root->val > key)
        {
            ceil = root->val;
            root = root->left;
        }
    }

    return ceil;
}

int findFloor(TreeNode *root, int key)
{

    int floor = -1;

    while (root != NULL)
    {
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }
        else if (root->val > key)
        {
            root = root->left;
        }
        else if (root->val < key)
        {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}

void makeBST(TreeNode *&root, int data)
{
    if (root == NULL)
    {
        root = new TreeNode(data);
        return;
    }

    if (data <= root->val)
    {
        makeBST(root->left, data);
    }
    else
    {
        makeBST(root->right, data);
    }
}
int main()
{

    TreeNode *root = NULL;
    makeBST(root, 10);
    makeBST(root, 5);
    makeBST(root, 15);
    makeBST(root, 2);
    makeBST(root, 6);


    cout << findCeil(root, 7) << endl;
    cout << findFloor(root, 7) << endl;

    return 0;
}