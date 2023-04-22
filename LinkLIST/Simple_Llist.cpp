#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node *nxt;

     //Constructor
        node() { this->nxt = NULL; }
        node(int data)
        {
             this->data = data;
            this->nxt = NULL;
        }
     //Distroctor
       ~node()
       {
           int value = this->data;
           //memory free
           if(this->nxt!=NULL)
           {
               delete nxt;
               this->nxt = NULL;
           }
           cout << "memory free for data " << value << endl;
       }
};

void Dltnode(node* &head,int pos)
{
    //Deletion of firsst node
    if(pos==1)
    {
        node *temp = head;
        head = head->nxt;
        temp->nxt = NULL;
        delete temp;
        return;
    }
  else
  {

        // deletion of last node or middle node
        int count = 1;
        node *crrnt = head;
        node *prev=NULL;
        while (count<pos)
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


void InsertAtHead(node* &head,int data)
{
    node *temp = new node(data);
    temp->nxt = head;
    head = temp;
}

void insertAtTail(node* &head, int data) {
    node* temp = new node(data);
    if(head == NULL){
        head = temp;
        return;
    }

    node *t = head;
    while(t->nxt != NULL){
        t = t->nxt;
    }
    t->nxt = temp;

}
int length(node* &head)
{
    int count = 0;
    node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->nxt;
    }
    return count;
}

void insertAtMid(node* &head, int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    if (pos>length(head))
    {
        insertAtTail(head, data);
        return;
    }

    node *n = new node(data), *temp;
    temp = head;
    int count = 1;
    while (count<pos-1)
    {
        temp = temp->nxt;
        count++;
    }

    n->nxt = temp->nxt;
    temp->nxt = n;
}

void print(node* &head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << "->";
        temp=temp->nxt;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
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
}