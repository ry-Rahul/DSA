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
Node *minVal(Node *root);

// !deletion in BST___________________________
Node *deleteNode(Node *root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // !case 1: no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        } 
        // !case 2: 1 child
        // left child
          if(root->left!=NULL && root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
          }
        // right child
           if(root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            delete root;
            return temp;
          }
        // !case 3: 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    
    else if(root->data > val){
        root->left = deleteNode(root->left, val);
        return root;
    }
    else{
        root->right = deleteNode(root->right, val);
        return root;
    }

}
// !min value in BST___________________________
Node *minVal(Node *root){
     Node *temp = root;
    while(temp->left!=NULL){
         temp = temp->left;
    }
    return temp;
}
// !max value in BST__________________________
Node *maxVal(Node *root){
      Node *temp = root;
    while(temp->right!=NULL){
         temp = temp->right;
    }
    return temp;
}
// !insertion in BST___________________________
Node *insertBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }
    return root;
}
// !insert____________________________________
void insert(Node *&root){

    cout<<"Insert data for root: ";
    int data; 
    cin>>data;
    while(data!=-1){
        root = insertBST(root, data);
        cin>>data;
    }
}
// !inorder traversal__________________________
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// !leveorder traversal________________________
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
// !main_______________________________________
int main(){

     Node *root = NULL;
        // insert(root);
        // 21 10 5 15 50 40 60 55 70 -1
     root->data = 50;
     root->left = new Node(40);

     cout << "Minimum value in Bst is: " << minVal(root)->data << endl;
     cout << "Maximum value in Bst is: " << maxVal(root)->data << endl;

     inorder(root);

     root = deleteNode(root, 50);
     cout << endl;
     inorder(root);

}