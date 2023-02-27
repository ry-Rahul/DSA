#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

// node insert_at_beg(node *head)
// {

// }
void insertion(node *&head)
{
    int d;
    cin >> d;

   

    if (head == NULL)
    {
        node *temp = new node;
        temp->data = d;
        temp->next = NULL;
        head = temp;
    }
    else
    {

        node *p= head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        node *temp = new node;
        temp->data = d;
        temp->next = NULL;
        p->next = temp;
    }
}
void print(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insertion(head);
    }

    print(head);
    return 0;
}