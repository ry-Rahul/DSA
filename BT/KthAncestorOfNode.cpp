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
// your task is to complete this function
Node *solve(Node *root,int &k,int node){
    
    // if root is null
    if(root==NULL){
        return NULL;
    }
    // if root is the node
    if(root->data == node){
        return root;
    }
    
    Node *leftAns = solve(root->left,k,node);
    Node *rightAns = solve(root->right,k,node);
    
    if(leftAns!=NULL && rightAns==NULL){
        
        k--;
        if(k<=0){
            // k is max so that it can't be used again and root is fixed
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL){
        
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    
    // else return NULL
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *temp = solve(root,k,node);
    // 
    if(temp==NULL || temp->data == node){
        return -1;
    }
    else{
        return temp->data;
    }
    
}

int main(){
    Node* root = new Node(1);
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
}