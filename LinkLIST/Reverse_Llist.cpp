#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)




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

    ~node()
    {
        int val;
        val = this->data;
        this->next=NULL;
        cout << "Memory  free for data " <<val<<endl;
    }
};

void deleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
     
      delete temp;
}
// void deletion(node *&head, int pos)
// {
//     if (pos == 1)
//     {
//         deleteAtHead(head);
//         return;
//     }
//     node *temp = head;
//     int count = 1;
//     while (temp != NULL && count != pos)
//     {
//         temp = temp->next;
//         count++;
//     }
//     temp->prev->next = temp->next;

//     if (temp->next != NULL)
//     {
//         temp->next->prev = temp->prev;
//     }
//     delete temp;
// }

// Recursive case for reverse a link list


node* recursiveReverse(node* &head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    node *newhead = recursiveReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
    
}

// Iterative call for reverse Link list
void reverseLink(node* &head)
{
    if(head==NULL || head->next==NULL)
        return;

    node *prev = NULL, *crrnt = head, *forw = NULL;
    while(crrnt!=NULL)
    {
        forw = crrnt->next;
        crrnt->next = prev;
        prev = crrnt;
        crrnt = forw;
    }

    head = prev;
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
    system("cls");
    node * head=NULL;
    insertAtHead(head, 45);
    insertAtHead(head, 4);
    insertAtHead(head, 78);
    insertAtHead(head, 12);

    display(head);

    // reverseLink(head);
    node *newhead = recursiveReverse(head);
    head = newhead;

    display(head);

    // deleteAtHead(head);
    // display(head);

    return 0;
}