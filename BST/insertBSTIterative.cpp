#include <bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
      val = data;
      left = NULL;
      right = NULL;
    }
};

void insertBST(TreeNode* &root, int data){
    if(root==NULL){
        root = new TreeNode(data);
        return;
    }

    TreeNode* temp = root;
    while(true){
        if(data>=temp->val){
            if(temp->right){
                temp = temp->right;
            }
            else{
                temp->right = new TreeNode(data);
                return;
            }
        }else{
            if(temp->left){
                temp = temp->left;
            }
            else{
                temp->left = new TreeNode(data);
                return;
            }
        }
    }
}

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){

    TreeNode* root = NULL;
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);


    inorder(root);
    cout<<endl;

  return 0;
}