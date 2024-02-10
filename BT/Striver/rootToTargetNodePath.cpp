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

bool getPath(TreeNode* root,int target,vector<int> &ans){
    if(root==NULL){
        return false;
    }


    ans.push_back(root->val);
    if(root->val==target){
        return true;
    }

    bool res = getPath(root->left,target,ans) || getPath(root->right,target,ans);
    if(res==true){
        return true;
    }
    ans.pop_back();

    return false;
}

vector<int> nodeTotargetPath(TreeNode* root,int target){
    if(root==NULL){
        return {};
    }

    vector<int> ans;
    getPath(root,target,ans);
    return ans;
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

    vector<int> ans = nodeTotargetPath(root,7);
    for(auto i:ans){
        cout<<i<<" ";
    }
  

  return 0;
}