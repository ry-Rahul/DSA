#include <bits/stdc++.h>
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

void flattenTree(Node* root){
    // 1. Recursively flatten left and right subtree
    // 2. Store the left tail and right tail
    // 3. store right subtree in temp and make left subtree as right subtree
    // 4. join right subtree to left tail
    // 5. return right tail


// base case 
     if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flattenTree(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node * t = root->right;
        while(t->right!=NULL){
            t = t->right;
        }
        t->right = temp;
    }
    if(root->right!=NULL){
        flattenTree(root->right);
    }
}

void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
  Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    printInorder(root);cout<<endl;

    flattenTree(root);

    printInorder(root);

    return 0;
}