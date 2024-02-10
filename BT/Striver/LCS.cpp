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

// Method 1: Using recursion and finding path to node and then comparing the paths to find the LCA of the two nodes p and q in the tree rooted at root. 
// Time complexity: O(n)
/* bool pathToNode(TreeNode* root,TreeNode* target,vector<TreeNode*>&ans){
        if(root==NULL){
            return false;
        }

        ans.push_back(root);
        if(root->val==target->val){
            return true;
        }

        if(pathToNode(root->left,target,ans) || pathToNode(root->right,target,ans)){
            return true;
        }

        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans1;
        vector<TreeNode*> ans2;

        pathToNode(root,p,ans1);
        pathToNode(root,q,ans2);

        TreeNode* res = NULL;
        int i=0;
        while(i<ans1.size() && i<ans2.size()){
            if(ans1[i]->val==ans2[i]->val){
                res = ans1[i];
            }
            i++;
        
        }

        return res;

    } */

// Method 2: Using recursion and finding the LCA of the two nodes p and q in the tree rooted at root.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            // left and right both are not NULL
            return root;
        }
    }
int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->right->left->left = new TreeNode(7);

    //                         1
    //                     /       \
    //                    2         3
    //                  /         /   \
    //                 4         5     6
    //                          /   
    //                         7

    TreeNode* res = lowestCommonAncestor(root,root->right->left->left,root->right->right);
    cout<<res->val;
    cout<<endl;

  

  return 0;
}