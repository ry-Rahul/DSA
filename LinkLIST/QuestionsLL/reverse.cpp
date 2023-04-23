#include <bits/stdc++.h>
using namespace std;
//  declaring linked list
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
// reversing a linked list using recursion
void reverseRecursily(node * &head, node *curr, node *prev){
    if(curr==NULL){
        head = prev;
        return;
    }
    node *forw = curr->next;
    reverseRecursily(head, forw, curr);
    curr->next = prev;
}

// reversing a linked list using iteration
void reverse(node *&head){
    node *pre = NULL;
    node *curr = head;

    reverseRecursily(head, curr, pre);

    // node *forw;
    // while(curr!=NULL){
    //     forw = curr->next;
    //     curr->next = pre;
    //     pre = curr;
    //     curr = forw;
    // }
    // head = pre;
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

int main(){

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);

    reverse(head);
    display(head);

    return 0;
}