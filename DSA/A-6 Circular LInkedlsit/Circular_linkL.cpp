#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

class Node
{
public:
    int data;
    Node *nxt;

    Node(int val)
    {
        data = val;
        nxt = NULL;
    }
};
void dltAtLast(Node *&head, int pos)
{
    Node *temp = head, *t;
    int count = 1;
    while (temp != head)
    {
        t = temp;
        temp = temp->nxt;
    }
    t->nxt = temp->nxt;
    delete temp;
}
void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "  ";
        temp = temp->nxt;
    } while (temp != head);
}
void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    Node *temp = head;
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
void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    Node *temp = head;

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
    Node *head = NULL;
    insertAtTail(head, 45);
    insertAtTail(head, 78);
    insertAtTail(head, 89);
    insertAtTail(head, 412);
    insertAtHead(head, 100);

    display(head);

    return 0;
}