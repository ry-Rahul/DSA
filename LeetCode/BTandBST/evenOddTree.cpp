#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// only one value in each level
bool isUnivalTree(TreeNode* root) {
        if(root == NULL){
        return true;
    }
    if(root->left != NULL && root->left->val != root->val){
        return false;
    }
    if(root->right != NULL && root->right->val != root->val){
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
bool levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if(temp==NULL){
            cout << "\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        if(level%2==0){

        }

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
}

bool isEvenOdd(TreeNode* root){
    bool ans = levelOrderTraversal(root);
    return ans;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = NULL;
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);

    bool ans = isEvenOdd(root);
    cout << ans << endl;
    // levelOrderTraversal(root);

  

  return 0;
}