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

    return 0;
}