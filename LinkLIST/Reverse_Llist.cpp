#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)




// declaring linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node()
    {
        int val;
        val = this->data;
        this->next=NULL;
        cout << "Memory  free for data " <<val<<endl;
    }
};

void deleteAtHead(Node *&head)
{
    Node *temp = head;
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


Node* recursiveReverse(Node* &head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    Node *newhead = recursiveReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
    
}

// Iterative call for reverse Link list
void reverseLink(Node* &head)
{
    if(head==NULL || head->next==NULL)
        return;

    Node *prev = NULL, *crrnt = head, *forw = NULL;
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
void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
// inserting element at tail
void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    Node *n = new Node(val);
    
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
// display a linked lsit
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int length(Node *head)
{
    int l = 0;
    Node *temp = head;
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
    Node * head=NULL;
    insertAtHead(head, 45);
    insertAtHead(head, 4);
    insertAtHead(head, 78);
    insertAtHead(head, 12);

    display(head);

    // reverseLink(head);
    Node *newhead = recursiveReverse(head);
    head = newhead;

    display(head);

    // deleteAtHead(head);
    // display(head);

    return 0;
}