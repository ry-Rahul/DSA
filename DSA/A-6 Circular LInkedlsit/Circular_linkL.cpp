#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

class node
{
public:
    int data;
    node *nxt;

    node(int val)
    {
        data = val;
        nxt = NULL;
    }
};
void dltAtLast(node *&head, int pos)
{
    node *temp = head, *t;
    int count = 1;
    while (temp != head)
    {
        t = temp;
        temp = temp->nxt;
    }
    t->nxt = temp->nxt;
    delete temp;
}
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "  ";
        temp = temp->nxt;
    } while (temp != head);
}
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        n->nxt = n;
        head = n;
        return;
    }

    while (temp->nxt != head)
    {
        temp = temp->nxt;
    }
    temp->nxt = n;
    n->nxt = head;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    while (temp->nxt != head)
    {
        temp = temp->nxt;
    }
    n->nxt = head;
    temp->nxt = n;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 45);
    insertAtTail(head, 78);
    insertAtTail(head, 89);
    insertAtTail(head, 412);
    insertAtHead(head, 100);

    display(head);

    return 0;
}