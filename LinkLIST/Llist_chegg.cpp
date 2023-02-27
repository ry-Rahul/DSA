#include<bits/stdc++.h>
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
int FindMin(node* &head)
{
    node *temp = head;
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
void DltAtVal(node* &head,int val)
{
     
    node *temp = head,*t;
    while (temp->data!=val)
    {
        t = temp;
        temp = temp->next;
    }
    t = temp->next;
    delete temp;
}
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

int main()
{
    node* head=NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);

    display(head);
    cout << FindMin(head);
}