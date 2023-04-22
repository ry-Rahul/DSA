#include<bits/stdc++.h>

#include<conio.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *nxt;
		
	Node(int val)
	{
		data=val;
		nxt=NULL;
	}
};

void display(Node* head)
{
	Node *t;
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<"->";
		t=t->nxt;
	}
	cout<<"NULL";
	cout<<endl;
}
void deletion_end(Node* &head)
{
	 Node *t1=NULL,*t2=head->nxt;
	
	if(head==NULL)
        cout<<"List is empty:"<<endl;
    else
    {
    	
    	while(t2->nxt!=NULL)
    	{
    		t1=t2;
    		t2=t2->nxt;
		}
		
		t1->nxt=NULL;
		delete t2;
	}
}
void insertAtHead(Node* &head,int val)
{
	Node *n=new Node(val);
	n->nxt=head;
	head=n;
}
void insertAtTail(Node* &head, int val)
{
	Node *n=new Node(val);
	
	if(head==NULL)
	{
		head=n;
		return;
	}
	
	Node *temp=head;
	while(temp->nxt!=NULL)
	{
		temp=temp->nxt;
		
	}
	temp->nxt=n;
	n->nxt=NULL;
}
bool search(Node* head,int key)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		   return true;
		   temp=temp->nxt;
	}
	return false;
}

int menu()
{
	int choice;
	cout<<endl<<"1. Insert at first";
	cout<<endl<<"2. Insert at Last";
	cout<<endl<<"3. Search the value";
	cout<<endl<<"4. Display Link list";
	cout<<endl<<"5. Deletion at the End";
	cout<<endl<<"6. Deletion at the Fisrt";
	cout<<endl<<"7. Exit";
	cout<<endl<<"Enter your choice";
	cin>>choice;
	return choice;
}


int main()
{

    int data;
	Node *head=NULL;
	
    

while(true)
	{
		// system("cls");
		//display(head);
		switch(menu())
		{
			case 1:
				cout<<"Enter data to insert:";
				cin>>data;
				insertAtHead(head,data);
			    break;
			case 2:
				cout<<"Enter data to Insert:";
				cin>>data;
				insertAtTail(head,data);
				break;
			case 3:
				cout<<"Enter the value:";
				cin>>data;
				cout<<search(head,data);
				break;
			case 4:
			    display(head);
				
				break;
			case 5:
				cout<<"Opps ! function is not defined:";
				cin>>data;
				break;
			case 6:
			     cout<<"Opps ! function is not defined:";
				 cin>>data;
				 break;
			case 7:
				exit(0);
				break;
			default:
				cout<<"Invalid Choice";
		}
	
      getch();
	//cout<<search(head,4)<<endl;
	
	
	
}
}