#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *prev;
        Node *next;

        //constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        ~Node()
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

void print(Node* head)
{
    Node *temp = head;

    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head)
{
    Node *temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAthead(Node* &head,int data)
{
    // List is empty
    if(head==NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,int data)
{
    if(head==NULL){
        insertAthead(head,data);
        return;
    }
    else
    {
        Node *temp = new Node(data);
        
        Node *curr = head;
        while (curr->next!=NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;

    }
   
}

void insertAtPos(Node* &head,int pos,int data)
{
    // insertion at head
    if(pos==1)
    {
        insertAthead(head,data);
        return;
    }

    Node *temp = head;
    int count = 1;
    
    while (count<pos-1)
    {
        temp = temp->next;
        count++;
    }
    
    //insertion at last node
    if(pos>getLength(head))
    {
        insertAtTail(head, data);
        return;
    }

    // insert at position

    Node *n = new Node(data);

    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;

}
void deleteAtHead(Node* &head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}
void deleteAtTail(Node* &head){
    Node *temp = head, *prev = NULL;
    while (temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

void Dltnode(Node* &head,int pos)
{
    //delet first or start node
    if(pos==1)
    {
        deleteAtHead(head);
        return;
     }

    else
    {
        //delet middle or last node
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count<pos)
        {
             prev= curr;
            curr = curr->next;
            count++;
        }

        //delet last node
        if(curr->next==NULL)
        {
            deleteAtTail(head);
            return;
        }

        //delet middle node
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;

    }
}
int main()
{
   Node *head = NULL;
   


    insertAthead(head, 1);
    print(head);

    insertAthead(head, 2);
    print(head);

    insertAthead(head, 3);
    print(head);
    
    insertAthead(head, 4);
    print(head);

    insertAtTail(head, 5);
    print(head);

    insertAtPos(head, 3, 6); 
    print(head);

    insertAtPos(head,1, 7); 
    print(head);

    insertAtPos(head,8, 8); 
    print(head);

    Dltnode(head, 1);
    print(head);

    Dltnode(head, 7);
    print(head);

    deleteAtHead(head);
    print(head);

    deleteAtTail(head);
    print(head);

    cout <<"length of list is -> "<< getLength(head)<<endl;
}