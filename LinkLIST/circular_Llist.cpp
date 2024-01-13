#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        //constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        ~Node()
        {
            int value = this->data;
            if(this->next!=NULL)
            {
                delete next;
                next = NULL;
            }
            cout << "memory is free for node with data -> " << value << endl;
        }
};

void insertnode(Node* &tail, int element, int data)
{
    // assuming that the element is present in the list
    if(tail==NULL)
    {
        Node *newnode = new Node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        //non empty list
        Node* curr=tail;
       
        while(curr->data!=element)
        {
            curr = curr->next;
        }
    
            //element found curr is representing element wala node
            Node *temp = new Node(data);
            temp->next = curr->next;
            curr->next = temp;
            

    }

}

void deletenode(Node* tail,int element)
{
    if(tail==NULL)
    {
        cout << "List is empty, please check agian" << endl;
        return;
    }
    Node *curr = tail;
    Node *prev = NULL;
    do
    {
        /* code */
        prev = curr;
        curr = curr->next;
        if(curr->data==element)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            return;
        }
    } while (curr!=tail);
    
    cout << "Element not found" << endl;
}

void print(Node* tail)
{
    if(tail==NULL){
        cout << "List is empty, please check agian" << endl;
        return;
    }
    Node *temp = tail;
    // temp=temp->next;
    do
    {
        /* code */
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp!=tail);
    
    cout << endl;
}


int main()
{
    Node *tail = NULL;

    insertnode(tail, 5, 8);
    print(tail);

    // insertnode(tail, 8, 12);
    // print(tail);

    // insertnode(tail, 12, 16);
    // print(tail);

    // insertnode(tail, 12, 100);
    // print(tail);

    // insertnode(tail, 12, 8);
    // print(tail);

    // insertnode(tail, 8, 55);
    // print(tail);

    deletenode(tail,8);
    print(tail);
}

