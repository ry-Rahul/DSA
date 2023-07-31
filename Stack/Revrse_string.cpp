#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    char *arr;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(int data);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
};
void Stack::push(int data)
{
    if (size - top > 1)
    {
        top++;
        arr[top] = data;
    }
    else
    {
        cout << "Stack overflow" << endl;
    }
}
void Stack::pop()
{
    if (top >= 0)
        top--;
    else
        cout << "stack underflow" << endl;
}
int Stack::peek()
{
    if (top >= 0)
        return arr[top];
    else
        return -1;
}

bool Stack::isEmpty()
{
    if (top < 0)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if (top == size - 1)
        return true;
    else
        return false;
}

int main()
{
    Stack st(15);

    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }

    string ans = "";

    while(!st.isEmpty())
    {
        char ch = st.peek();
        ans.push_back(ch);
        st.pop();
    }

    cout << "answer is >> " << ans << endl;
}
