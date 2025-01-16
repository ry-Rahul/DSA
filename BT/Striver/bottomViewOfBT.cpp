#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> bottomView(Node *root)
{
    // Your Code Here

    map<int, int> mp;
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {

        Node *node = q.front().first;
        int xline = q.front().second;
        q.pop();

        mp[xline] = node->data;
        if (node->left)
        {
            q.push({node->left, xline - 1});
        }
        if (node->right)
        {
            q.push({node->right, xline + 1});
        }
    }

    for (auto it : mp)
    {
        v.push_back(it.second);
    }

    return v;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = bottomView(root);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}