#include <bits/stdc++.h>
using namespace std;

// declaring linked list

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// inserting element at head
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
// inserting element at tail
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
// display a linked lsit
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *FindMidOptimise(node *head)
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

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

node *findmid(node *head)
{

    node *temp = head;
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
    node *head = NULL;
    insertAtHead(head, 78);
    insertAtHead(head, 7);
    insertAtHead(head, 19);
    insertAtHead(head, 89);
    insertAtHead(head, 100);
    insertAtHead(head, 22);

    display(head);

    // node *newhead = FindMidOptimise(head);
    node *newhead = findmid(head);
    display(newhead);
}