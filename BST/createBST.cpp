#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

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

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data <= root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// recursive way
bool searchElement(Node *root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    else if(data < root->data){
        return searchElement(root->left, data);
    }
    else{
        return searchElement(root->right, data);
    }
}

// iterative way
bool searchInBst(Node *root, int data){

    Node *temp = root;
    while (temp!= NULL){
        if(data == temp->data){
            return true;
        }
        else if(data < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
int main()
{

    Node *root = NULL;

    cout << "Enter data to create BST: ";
    // 21 10 5 15 50 40 60 55 70 -1
    takeInput(root);

    // inorder(root);
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    // search element
    int data = 56;
    cout << "Search element: " <<searchInBst(root,data) << endl;

    return 0;
}
