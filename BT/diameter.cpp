#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int heightOfTree(node* root){
    if(root == NULL)
        return 0;
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    int ans = max(lheight,rheight) + 1;

    return ans;
}

int main()
{
    node *root = NULL;
    return 0;
}