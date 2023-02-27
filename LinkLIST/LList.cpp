#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    // data
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void insertAtTail(node *&head, int data)
{
    node *n = new node(data);

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAtHead(node *&head, int data)
{

    // create new node

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(node *&head, int data, int position)
{
    // initialize a node
    int count = 1;
    node *n = new node(data);
    node *temp = head;

    // total length of link list
    int length = 1;
    node *len = head;
    while (len != NULL)
    {
        len = len->next;
        length++;
    }
    delete len;

    // Insertion at first position
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    // insertion at last position
    if (position == length + 1)
    {
        insertAtTail(head, data);
        return;
    }

    //    insertion at position
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
}

// deletion
void deletNode(node *&head, int position)
{

    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deletion any middle node or last node
        node *curr = head;
        node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{

    //  creating a object n and after that gives its address to a pointer head of node type
    // node n = node(10);
    // node *head = &n;

    //  create a new node node1
    // node *node1 = new node(10);

    // head pointer to node1
    // node *head = node1;

    node *head = NULL;

    insertAtHead(head, 45);
    print(head);
    insertAtHead(head, 78);
    print(head);
    insertAtTail(head, 100);
    print(head);
    insertAtTail(head, 56);
    print(head);
    insertAtTail(head, 89);
    print(head);
    insertAtPosition(head, 3500, 3);
    insertAtPosition(head, 400, 1);
    insertAtPosition(head, 900, 8);

    // 78 45 10

    print(head);

    deletNode(head, 1);
    print(head);
    deletNode(head, 7);
    print(head);

    return 0;
}
