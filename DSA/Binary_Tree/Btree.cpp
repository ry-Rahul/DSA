#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
class BST
{
private:
  struct node
  {
    int data;
    node *right;
    node *left;
  };
  node *root;

public:
  BST() { root = NULL; }

  void insertt(int data);
};
void BST::insertt(int item)
{
  node *n = new node;
  n->left = NULL;
  n->right = NULL;
  n->data = item;

  if (root == NULL)
  {
    root = n;
  }
  else
  {

    while (true)
    {
      node *ptr = root;

      if (ptr->data == item)
      {
        // duplicate item
        delete n;
        break;
      }
      else if (ptr->data > item)
      {
        if (ptr->left == NULL)
        {
          ptr->left = n;
          break;
        }
        else
        {
          ptr = ptr->left;
        }
      }

      else
      {
        if (ptr->right == NULL)
        {
          ptr->right = n;
          break;
        }
        else
        {
          ptr = ptr->right;
        }
      }

    } // end of while loop
  }
}

int main()
{
  BST b;
  b.insertt(50);

  return 0;
}