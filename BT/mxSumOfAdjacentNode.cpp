#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

 pair<int,int> solve(Node *root){
        
        if(root==NULL){
            pair<int,int> ans = make_pair(0,0);
            return ans;
        }
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns= solve(root->right);
        
        pair<int,int> res;
        
        // first -> maximum sum by including node at current node
        // second -> maximum sum by excluding node at current node

        res.first  = root->data + leftAns.second + rightAns.second;
        res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
        
        return res;
        
    }
    
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans= solve(root);
        return max(ans.first ,ans.second);
    }
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    root->left->left->left->left = new Node(16);
    root->left->left->left->right = new Node(17);
    root->left->left->right->left = new Node(18);
    root->left->left->right->right = new Node(19);
    root->left->right->left->left = new Node(20);
    root->left->right->left->right = new Node(21);
    root->left->right->right->left = new Node(22);
    root->left->right->right->right = new Node(23);
    root->right->left->left->left = new Node(24);
    root->right->left->left->right = new Node(25);
    root->right->left->right->left = new Node(26);
    root->right->left->right->right = new Node(27);
    root->right->right->left->left = new Node(28);
    root->right->right->left->right = new Node(29);
    root->right->right->right->left = new Node(30);
    root->right->right->right->right = new Node(31);
    root->left->left->left->left->left = new Node(32);
    root->left->left->left->left->right = new Node(33);
    root->left->left->left->right->left = new Node(34);

    cout<<getMaxSum(root);

    return 0;
}