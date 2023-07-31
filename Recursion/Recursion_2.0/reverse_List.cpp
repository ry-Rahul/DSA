#include<bits/stdc++.h>
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

 Node reverse(Node*  &head)
 {
    if(head==NULL || head->next==NULL)
    {
         return head;
    }
    Node *temp = head->next;
    head->next = NULL;
    Node *newhead = reverse(temp);
    temp->next = head;
   head= newhead;
 }

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

int main()
{
    Node *head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);

    display(head);

    reverse(head);
    display(head);
}