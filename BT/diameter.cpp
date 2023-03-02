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
int diameterOfBinaryTree(node* root){
    // base case
    if(root == NULL)
        return 0;
    
    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = heightOfTree(root->left) + heightOfTree(root->right) +1;

    int ans = max(op3,(max(op1,op2)));
    
    return ans;

}
int main()
{
    node *root = NULL;
    return 0;
}