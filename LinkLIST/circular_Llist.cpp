#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *next;

        //constructor
        node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        ~node()
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

void insertnode(node* &tail, int element, int data)
{
    // assuming that the element is present in the list
    if(tail==NULL)
    {
        node *newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        //non empty list
        node* curr=tail;
        while(curr->data!=element)
        {
            curr = curr->next;
        }
    
            //element found curr is representing element wala node
            node *temp = new node(data);
            temp->next = curr->next;
            curr->next = temp;

    }

}

void deletenode(node* tail,int element)
{
    if(tail=NULL)
    {
        cout << "List is empty, please check agian" << endl;
    }
    else{
        // asuming element is present in the list

        node *prev= tail;
        node *curr = prev->next;

        while (curr->data!=element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node* tail)
{
    node *temp = tail;
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
    node *tail = NULL;

    insertnode(tail, 5, 8);
    print(tail);

    insertnode(tail, 8, 12);
    print(tail);

    insertnode(tail, 12, 16);
    print(tail);

    insertnode(tail, 12, 100);
    print(tail);

    insertnode(tail, 12, 8);
    print(tail);

    deletenode(tail, 12);
    print(tail);
}

