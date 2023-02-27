#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *prev;
        node *next;

        //constructor
        node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        ~node()
        {
            int val = this->data;
            if(next!=NULL)
            {
                delete next;
                next = NULL;
            }
            cout << "memory free for node with data -> " << val << endl;  
        }
};

void print(node* head)
{
    node *temp = head;

    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node* head)
{
    node *temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAthead(node* &head,node* &tail,int data)
{
    // List is empty
    if(head==NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    else{

        node* temp=new node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;  
    }
}

void insertAtTail(node* &head,node* &tail,int data)
{
    if(tail==NULL)
    {
        node *temp = new node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
   
}

void insertAtPos(node* &head,node*&tail ,int pos,int data)
{
    // insertion at head
    if(pos==1)
    {
        insertAthead(head,tail,data);
        return;
    }

    node *temp = head;
    int count = 1;
    
    while (count<pos-1)
    {
        temp = temp->next;
        count++;
    }
    
    //insertion at last node
    if(temp->next==NULL)
    {
        insertAtTail(head,tail, data);
        return;
    }

    // insert at position

    node *n = new node(data);

    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;

}

void Dltnode(node* &head,int pos)
{
    //delet first or start node
    if(pos==1)
    {
        node *temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
     }

    else
    {
        //delet middle or last node
        node *curr = head;
        node *temp = NULL;
        int count = 1;
        while (count<pos)
        {
            temp = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        if(curr->next!=NULL)
        curr->next->prev = temp;
        temp->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // node *node1 = new node(10);
    // node* head = node1;
    // node* tail = node1;

    node* head = NULL;
    node* tail = NULL;
    // print(head);


    insertAthead(head,tail, 1);
    print(head);

    insertAthead(head,tail, 2);
    print(head);

    insertAthead(head,tail, 3);
    print(head);
    
    insertAthead(head,tail, 4);
    print(head);

    insertAtTail(head,tail, 5);
    print(head);

    insertAtPos(head,tail, 3, 6); 
    print(head);

    insertAtPos(head,tail, 1, 7); 
    print(head);

    insertAtPos(head,tail, 8, 8); 
    print(head);

    Dltnode(head, 1);
    print(head);

    Dltnode(head, 7);
    print(head);

    cout <<"length of list is -> "<< getLength(head)<<endl;
}