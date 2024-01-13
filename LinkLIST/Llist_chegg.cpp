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
int FindMin(Node* &head)
{
    Node *temp = head;
    int min = head->data;
    while (temp!=NULL)
    {
         if(temp->data<min)
         {
             min = temp->data;
         }
         temp = temp->next;
    }
    return min;
}
void DltAtVal(Node* &head,int val)
{
     
    Node *temp = head,*t;
    while (temp->data!=val)
    {
        t = temp;
        temp = temp->next;
    }
    t = temp->next;
    delete temp;
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
    Node* head=NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);

    display(head);
    cout << FindMin(head);
}