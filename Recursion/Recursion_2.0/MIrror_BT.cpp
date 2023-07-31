#include <bits/stdc++.h>
using namespace std;

mirror(node root)
{
    if(root==NULL)
        return root;
    node leftsubtreemirror = mirror(root->left)
        node rightsubtreemirror = mirror(root->right)

    root->right = leftsubtreemirror;
    root->left = rifhtsubtreemirror;

    return root;
}

int main()
{
  

  return 0;
}