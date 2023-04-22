#include <bits/stdc++.h>
using namespace std;

// declaring linked list

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
// inserting element at head
void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
// inserting element at tail
void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    Node *n = new Node(val);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
// display a linked lsit
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int length(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

Node *FindMidOptimise(Node *head)
{
    //  OPtimise Algo for Find middle of linllist
    // if empty list return null
    // 1 node --- head
    // 2 node --- head->next;
    // Algo  with two pointer slow and fast
    if (head == NULL || head->next == NULL)
        return head;

    // 2nodes
    if (head->next->next == NULL)
        return head->next;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *findmid(Node *head)
{

    Node *temp = head;
    int len = length(head);
    int mid = (len / 2);
    int pos = 0;
    while (pos < mid)
    {
        temp = temp->next;
        pos++;
    }
    return temp;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 78);
    insertAtHead(head, 7);
    insertAtHead(head, 19);
    insertAtHead(head, 89);
    insertAtHead(head, 100);
    insertAtHead(head, 22);

    display(head);

    // node *newhead = FindMidOptimise(head);
    Node *newhead = findmid(head);
    display(newhead);
}