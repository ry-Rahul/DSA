#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
int count = -1;
class Node
{
public:
    int data;
    Node *nxt;
    Node *prev;

    Node(int val)
    {
        data = val;
        nxt = NULL;
        prev = NULL;
    }
};
void dltAtHead(Node *&start)
{
    Node *t;
    t = start;
    t->prev = NULL;
    t->nxt = NULL;
    start = NULL;
    delete t;
    count--;
}
void dltNode(Node *&start, int pos)
{

    if (pos == 1)
    {
        dltAtHead(start);
        return;
    }
    Node *t, *n = NULL;
    t = start;
    int count = 1;
    while (t != NULL)
    {
        if (count == pos)
            break;

        t = t->nxt;
        count++;
    }
    if (t->nxt != NULL)
    {
        t->nxt->prev = t->prev;
        t->prev->nxt = t->nxt;
    }
    else
    {

        t->prev->nxt = NULL;
        t->prev = t->prev->prev;
    }

    delete t;
    count--;
}
void insertAtHead(Node *&start, int data)
{
    Node *n = new Node(data);

    n->nxt = start;
    start->prev = n;
    start = n;
    count++;
}
void insertAtTail(Node *&start, int data)
{
    Node *n = new Node(data);
    Node *temp = start;

    if (start == NULL)
    {
        n->prev = NULL;
        start = n;
        return;
    }
    while (temp->nxt != NULL)
    {
        temp = temp->nxt;
    }
    temp->nxt = n;
    n->prev = temp;
    n->nxt = NULL;
    count++;
}
void display(Node *start)
{
    Node *temp = start;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;
}
void evenafterodd(Node *&start)
{
    Node *odd = start;
    Node *even = start->nxt;
    Node *evenstart = even;
    while (odd->nxt != NULL && even->nxt != NULL)
    // motive last even node is null and
    { // if node is even even->nxt=NULL then evenstart start with the end of odd one
      //  if node is odd  then last odd node initialize with null and its sure last even node is not null
      //
        odd->nxt = even->nxt;
        odd = odd->nxt;
        even->nxt = odd->nxt;
        even = even->nxt;
    }
    odd->nxt = evenstart;
    if (even->nxt != NULL)
    {
        odd->nxt = evenstart;
        even->nxt = NULL;
    }
}
int main()
{
    // system("color a");

    Node *start = NULL;
    insertAtTail(start, 1);
    insertAtTail(start, 2);
    insertAtTail(start, 3);
    insertAtTail(start, 4);
    insertAtTail(start, 5);
    insertAtTail(start, 6);
    insertAtTail(start, 7);
    insertAtTail(start, 8);

    display(start);

    // insertAtHead(start,7);
    // dltNode(start,4);

    evenafterodd(start);
    display(start);

    getch();
    return 0;
}