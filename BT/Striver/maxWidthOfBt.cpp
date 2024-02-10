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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            long long size = q.size();
            long long curMin = q.front().second;
            long long leftMost, rightMost;

            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
                TreeNode* temp = q.front().first;
                q.pop();
                if (i == 0)
                    leftMost = cur_id;
                if (i == size - 1)
                    rightMost = cur_id;
                if (temp->left)
                    q.push({temp->left, cur_id * 2 + 1});
                if (temp->right)
                    q.push({temp->right, cur_id * 2 + 2});
            }
            ans = max(ans, int(rightMost - leftMost) + 1);
        }
        return ans;
    }
};
int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);


    Solution obj;
    cout<<obj.widthOfBinaryTree(root);
    
  

  return 0;
}