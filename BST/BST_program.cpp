#include <cstddef>
#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *left, *right;
};
node *root = NULL;
node *LOC = NULL;
node *PAR = NULL;
node *ptr, *save;
void search(int item)
{
    if (root == NULL)
    {
        LOC = NULL;
        PAR = NULL;
        return;
    }
    if (item == root->info)
    {
        LOC = root;
        PAR = NULL;
        return;
    }
    if (item < root->info)
    {
        ptr = root->left;
        save = root;
    }
    else
    {
        ptr = root->right;
        save = root;
    }
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            LOC = ptr;
            PAR = save;
            return;
        }
        if (item < ptr->info)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    LOC = NULL;
    PAR = save;
}
void insert(int d)
{
    search(d);
    if (LOC != NULL)
    {
        cout << "element already exist";
        return;
    }
    node *newnode = new node;
    newnode->info = d;
    newnode->left = NULL;
    newnode->right = NULL;
    if (PAR == NULL)
        root = newnode;
    else
    {
        if (d < PAR->info)
            PAR->left = newnode;
        else
            PAR->right = newnode;
    }
}
void inorder(node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout << ptr->info;
        inorder(ptr->right);
    }
}
void CASEA(node *l, node *p)
{
    node *child;
    if (l->left == NULL && l->right == NULL)
        child = NULL;
    else if (l->left != NULL)
        child = l->left;
    else
        child = l->right;
    if (p != NULL)
    {
        if (l == p->left)
            p->left = child;
        else
            p->right = child;
    }
    else
        root = child;
}
void CASEB(node *L, node *P)
{
    node *ptr, *save, *SUC, *PARSUC;
    ptr = L->right;
    save = L;
    while (ptr->left != NULL)
    {
        save = ptr;
        ptr = ptr->left;
    }
    SUC = ptr;
    PARSUC = save;
    CASEA(SUC, PARSUC);
    if (PAR != NULL)
    {
        if (L == PAR->left)
            PAR->left = SUC;
        else
            PAR->right = SUC;
    }
    else
        root = SUC;
    SUC->left = L->left;
    SUC->right = L->right;
}

void deleteItem(int a)
{
    search(a);
    if (LOC == NULL)
    {
        cout << "Element doesnot exist";
        return;
    }
    if (LOC->left != NULL && LOC->right != NULL)
        CASEB(LOC, PAR);
    else
        CASEA(LOC, PAR);
}
int main()
{
    insert(40);
    insert(70);
    insert(20);
    insert(35);
    insert(32);
    insert(65);
    cout << " traverse the tree";
    inorder(root);
    insert(58);
    insert(45);
    insert(70);
    insert(65);
    cout << " traverse the tree";
    inorder(root);
    deleteItem(70);
    deleteItem(65);
    cout << " traverse the tree";
    inorder(root);

    return 0;
}