#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* lca(Node* root ,int n1 ,int n2 ){
    //    
       if(root==NULL){
           return NULL;
       }
       if(root->data==n1||root->data==n2){
           return root;
       }
       
       Node *left = lca(root->left,n1,n2);
       Node *right= lca(root->right,n1,n2);
       
       if(left!=NULL && right!=NULL){
           return root;
       }
       else if(left!=NULL && right ==NULL){
           return left;
       }
       else if(left==NULL && right!=NULL){
           return right;
       }
       else{
           return NULL;
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

    

    return 0;

}