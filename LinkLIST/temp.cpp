#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// node insert_at_beg(node *head)
// {

// }
void insertion(Node *&head)
{
    int d;
    cin >> d;

   

    if (head == NULL)
    {
        Node *temp = new Node;
        temp->data = d;
        temp->next = NULL;
        head = temp;
    }
    else
    {

        Node *p= head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        Node *temp = new Node;
        temp->data = d;
        temp->next = NULL;
        p->next = temp;
    }
}
void print(Node *head)
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = NULL;

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insertion(head);
    }

    print(head);
    return 0;
}