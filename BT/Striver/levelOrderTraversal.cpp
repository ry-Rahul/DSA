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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }

            level.push_back(temp->val);
        }

        ans.push_back(level);
    }

    return ans;
}
int main(){
  

  return 0;
}