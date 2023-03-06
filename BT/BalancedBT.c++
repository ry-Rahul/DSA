#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfTree(node *root)
{
    if (root == NULL)
        return 0;
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    int ans = max(lheight, rheight) + 1;

    return ans;
}

// its time complexity is O(n^2)
int diameterOfBinaryTree(node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    int ans = max(op3, (max(op1, op2)));

    return ans;
}

// Its time complexity is O(n)
pair<int, int> fastDiameter(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op3, (max(op1, op2)));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

// but its time complexity is O(n^2) so we can use fastIsBalanced function
bool isBalanced(node *root){
    if(root == NULL){
        return true;
    }
    
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;
   
     if(left && right && diff){
        return true;
     }
     else{
         return false;
         }
}

// fastIsBalanced function time complexity is O(n)
pair<bool,int> isBalancedFast(node *root){
    if(root==NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;
    
    pair<bool, int> ans;
    ans.second= max(left.second, right.second) + 1;
    
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);

    // balancedFast function
    pair<bool, int> ans = isBalancedFast(root);
    if(ans.first){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}