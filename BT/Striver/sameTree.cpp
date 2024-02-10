#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL){
        return p==q;
    }
    bool left = isSameTree(p->left,q->left);
    bool right = isSameTree(p->right,q->right);

    return p->val==q->val && left && right;
}
int main(){
  

  return 0;
}