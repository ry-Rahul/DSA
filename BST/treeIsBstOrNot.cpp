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
// !BST or NOT 
bool solve(Node *root,int min,int max){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool leftValid = solve(root->left, min, root->data-1);
    bool rightValid = solve(root->right, root->data+1, max);
    return leftValid && rightValid;

}

bool validateBst(Node *root){
    return solve(root, INT_MIN, INT_MAX);
}

// !levelorder traversal__________________________
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
     insert(root);
        // 21 10 5 15 50 40 60 55 70 -1

        levelOrderTraversal(root);
        cout << endl;
        inorder(root);
        //  root = deleteNode(root, 50);
        cout << endl;
        //  inorder(root);
        if (validateBst(root))
        {
            cout<<"BST"<<endl;
        }
         else{
            cout<<"Not BST"<<endl;
        }

}