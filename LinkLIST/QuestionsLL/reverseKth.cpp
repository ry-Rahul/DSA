#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

// recursive way to reverse a linked list
Node *reverseKthElement(Node *head, int k){
    if(head==NULL){
        return head;
    }

    // step 1;
    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

// step 2 recursion 
    if(next!=NULL){
        head->next = reverseKthElement(next, k);
    }

    return prev;
}
Node* reverseRecursive(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool isCircularList(Node *head){
    if(head==NULL){
        return true;
    }
    
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    return (temp==head);
}

void printNode(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}




int main()
{
    Node *head = NULL;
    Node *newNode = new Node(1);
    head = newNode;
    newNode->next = new Node(2);
    newNode->next->next = new Node(3);
    newNode->next->next->next = new Node(4);
    newNode->next->next->next->next = new Node(5);
    newNode->next->next->next->next->next = new Node(6);
    newNode->next->next->next->next->next->next = new Node(7);
    newNode->next->next->next->next->next->next->next = new Node(8);
    newNode->next->next->next->next->next->next->next->next = head;

    // printNode(head);
    // cout << "____________________" << endl;

    // Node* newHead = reverseKthElement(head,2);
    // printNode(newHead);

    cout<<isCircularList(head)<<endl;
    return 0;
}