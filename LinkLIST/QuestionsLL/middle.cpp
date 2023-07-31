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

// finding middle element of a linked list
void find_middle(node *head){
    int mid = (length(head)/2)+1;

    node *temp = head;
    for(int i=1; i<mid; i++){
        temp = temp->next;
    }
    cout << temp->data << endl;
}

// optimize solution for finding middle element of a linked list
node* getMiddle(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head->next;
    }
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    
    cout<<"Lenght of linked list is: "<<length(head)<<endl;
    display(head);
    find_middle(head);

    node *mid = getMiddle(head);
    cout <<"Middle element of linked List with int type data is "<< mid->data << endl;
    

  return 0;
}