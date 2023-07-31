#include <bits/stdc++.h>
using namespace std;

// !class BST_____________________________________
class BST
{
private:
// public:
    struct node
    {
        int item;
        node *left;
        node *right;
    };
    node *root;

// protected:
public:
    void inorderT(node *ptr);
    void preorderT(node *ptr);
    void postorderT(node *ptr);

// public:
    BST() { root = NULL; }
    void insert(int data);
    void inorder();
    void preorder();
    void postorder();
    void deletenode (int data);
};

//! function insert_______________________________
void BST::insert(int data)
{
    node *n = new node;
    n->left = NULL;
    n->item = data;
    n->right = NULL;

    if (root == NULL)
        root = n;
    else
    {

        node *ptr = root;

        while (true)
        {

            if (ptr->item == data)
            {
                // duplicate value
                delete n;
                break;
            }
            else if (data < ptr->item)
            {
                // insert data in left subtree
                if (ptr->left == NULL)
                {
                    ptr->left = n;
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else
            {
                // insert data in right subtree
                if (ptr->right == NULL)
                {
                    ptr->right = n;
                    break;
                }
                else
                    ptr = ptr->right;
            }

        } // end of while loop
    }     // end of else
}

// !function delete________________________________
void BST::deletenode(int data)
{

}

//!function inorder_____________________________________
void BST::preorderT(node *ptr)
{
    if(ptr)
    {
        cout << ptr->item <<" ";
        preorderT(ptr->left);
        preorderT(ptr->right);
    }
}
// !function preorder_____________________________________
void BST::preorder()
{
    preorderT(root);
}

// !function postorder_____________________________________
void BST::postorderT(node *ptr)
{
    if(ptr)
    {
        postorderT(ptr->left);
        postorderT(ptr->right);
        cout << ptr->item << " ";
    }
}
void BST::postorder()
{
    postorderT(root);
}


void BST::inorderT(node *ptr)
{
    if (ptr)
    {
        inorderT(ptr->left);
        cout << " " << ptr->item;
        inorderT(ptr->right);
    }
}
void BST::inorder()
{
    inorderT(root);
}

int main()
{

    BST tree;
    // BST node* root = NULL;

    tree.insert(50);
    tree.insert(70);
    tree.insert(30);
    tree.insert(60);
    tree.insert(35);
    tree.insert(90);

    tree.postorder();
    return 0;
}