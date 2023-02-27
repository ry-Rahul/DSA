#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
class CLL
{
private:
	struct node
	{
		int data;
		node *nxt;
	};
	node *last;

public:
	CLL() { last = NULL; }

	void insertatstart(int data);
	void insertatlast(int data);
	void dltfirst();
	void dltlast();

	~CLL();
};
void CLL::insertatstart(int data)
{
	node *n;
	n = new node;
	n->data = data;
	if (last == NULL)
	{
		n->nxt = n;
		last = n;
	}
	else
	{
		n->nxt = last->nxt;
		last->nxt = n;
		last = n;
	}
}
void CLL::dltlast()
{
	node *t;
	if (last)
	{

		if (last->nxt = last)
		{
			delete last;
			last = NULL;
		}
		else
		{
			t = last->nxt;
			while (t->nxt != last)
			{
			}
		}
	}
	else
	{
		cout << "Underflow";
	}
}