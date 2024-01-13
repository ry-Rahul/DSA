#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *nxt;

    // Constructor
    Node() { this->nxt = NULL; }
    Node(int data)
    {
        this->data = data;
        this->nxt = NULL;
    }
    // Distroctor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->nxt != NULL)
        {
            delete nxt;
            this->nxt = NULL;
        }
        cout << "memory free for data " << value << endl;
    }
};

void deleteHead(Node *&head)
{
    Node *temp = head;
    head = head->nxt;
    temp->nxt = NULL;
    delete temp;
}
void deleteLast(Node *&head)
{
    Node *temp = head, *prev = NULL;
    while (temp->nxt != NULL)
    {
        prev = temp;
        temp = temp->nxt;
    }
    prev->nxt = NULL;
    delete temp;
}
void deleteNode(Node *&head, int pos)
{
    // Deletion of firsst node
    if (pos == 1)
    {
        deleteHead(head);
        return;
    }
    else
    {

        // deletion of last node or middle node
        int count = 1;
        Node *crrnt = head;
        Node *prev = NULL;
        while (count < pos)
        {
            prev = crrnt;
            crrnt = crrnt->nxt;
            count++;
        }
        prev->nxt = crrnt->nxt;
        crrnt->nxt = NULL;
        delete crrnt;
    }
}

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->nxt = head;
    head = temp;
}

void insertAtTail(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *t = head;
    while (t->nxt != NULL)
    {
        t = t->nxt;
    }
    t->nxt = temp;
}
int length(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->nxt;
    }
    return count;
}

void insertAtMid(Node *&head, int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    if (pos > length(head))
    {
        insertAtTail(head, data);
        return;
    }

    Node *n = new Node(data), *temp;
    temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->nxt;
        count++;
    }

    n->nxt = temp->nxt;
    temp->nxt = n;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->nxt;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, 5);
    InsertAtHead(head, 4);
    InsertAtHead(head, 3);
    InsertAtHead(head, 2);

    print(head);

    insertAtTail(head, 6);
    insertAtTail(head, 7);

    print(head);

    insertAtMid(head, 4, 100);
    insertAtMid(head, 1, 1);
    insertAtMid(head, 9, 999);

    print(head);
    cout << "Length of linked list is " << length(head) << endl;

    deleteNode(head, 5);
    print(head);
    deleteHead(head);
    print(head);
    deleteLast(head);
    print(head);
}