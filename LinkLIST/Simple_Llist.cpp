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

/*
void InsertAtTail(node* &head,int data)
{
    if(head==NULL)
    {
        InsertAtHead(head, data);
        return;
    }
    else
    {
        node *n = new node(data), *temp;
        n->nxt = NULL;
        temp = head;

        while (temp->nxt != NULL)
        {
            temp = temp->nxt;
        }
        temp->nxt = n;
    }
   
}
*/

void InsertAtTail(node* &tail,int data)
{
    node *temp = new node(data);
    tail->nxt = temp;
    tail = temp;
}

void InsertAtMid(node* &tail,node *&head, int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
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
    if (temp->nxt == NULL)
    {
        InsertAtTail(tail, data);
        return;
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
    // node *head=NULL,*tail = NULL;

    node *node1 = new node(10);
    
    // cout << node1->data << endl;
    // cout << node1->nxt << endl;
     node *head = node1;
     node *tail = node1;
     print(head);
     
     InsertAtHead(head, 45);
     InsertAtHead(head, 10);
     InsertAtHead(head, 20);
     print(head);
      InsertAtTail(tail, 100);
      InsertAtTail(tail, 200);
     print(head);
       InsertAtMid(tail,head, 7, 500);
     print(head);

     cout <<"head->data "<< head->data << endl;
     cout <<"tail->data "<< tail->data << endl;

     Dltnode(head,5);
     print(head);

     cout << "head->data " << head->data << endl;
     cout << "tail->data " << tail->data << endl;

     //  print(head);
}