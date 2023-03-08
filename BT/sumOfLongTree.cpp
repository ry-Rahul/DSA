
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

void solve(Node *root, int sum, int &maxsum, int len, int &maxlen)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }

        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }

        return;
    }

    sum += root->data;

    solve(root->left, sum, maxsum, len + 1, maxlen);
    solve(root->right, sum, maxsum, len + 1, maxlen);
}
int sumOfLongRootToLeafPath(Node *root)
{

    int sum = 0;
    int maxsum = INT_MIN;

    int len = 0;
    int maxlen = 0;

    solve(root, sum, maxsum, len, maxlen);
    return maxsum;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(1);
    root->right->left->left = new Node(0);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->right = new Node(10);
    root->right->right->left->right->right = new Node(11);
    cout << sumOfLongRootToLeafPath(root);
    return 0;
}