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

void makeBST(TreeNode *&root, int data)
{
    if (root == NULL)
    {
        root = new TreeNode(data);
        return;
    }

    if (data < root->val)
    {
        makeBST(root->left, data);
    }
    else
    {
        makeBST(root->right, data);
    }
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* succ = NULL;
    while(root != NULL){
        if(p->val < root->val){
            succ = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return succ;
}
int main(){

    TreeNode* root = NULL;
    makeBST(root, 5);
    makeBST(root, 3);
    makeBST(root, 4);
    makeBST(root, 2);
    makeBST(root, 1);
    makeBST(root, 7);
    makeBST(root, 6);
    makeBST(root, 9);
    makeBST(root, 8);
    makeBST(root, 10);
    TreeNode* p = root->right->right->left;
    TreeNode* ans = inorderSuccessor(root, p);
    cout<<ans->val<<endl;


  

  return 0;
}