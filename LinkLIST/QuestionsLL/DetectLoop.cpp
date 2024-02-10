#include <bits/stdc++.h>
using namespace std;

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
};
// makecycle
void makeCycle(Node* head, int pos){
    Node* temp = head;
    Node* startNode;
    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

// Detect loop
bool detectLoop(Node *head)
{
    if(head == NULL){
        return false;
    }
    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout<<"Loop found at "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// recursive way to reverse a linked list
Node *reverseKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    // step 1;
    int count = 0;
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 recursion
    if (next != NULL)
    {
        head->next = reverseKthElement(next, k);
    }

    return prev;
}
Node *reverseRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool isCircularList(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    return (temp == head);
}

void insertAtTail(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
}
void printNode(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// remove cycle
void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);
    fast = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);  
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);


    makeCycle(head, 4);

    cout << detectLoop(head) << endl;
    // printNode(head);
    return 0;
}