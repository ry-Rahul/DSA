#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
        int size; 
        int *arr;
        int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
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
     if(size-top >1)
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
     if(top>=0)
         top--;
    else
        cout << "stack underflow" << endl;
}
int Stack::peek()
{
     if(top>=0)
         return arr[top];
     else
         return -1;
}

bool Stack::isEmpty()
{
    if(top<0)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if (top == size -1)
        return true;
    else
        return false;
}

int main()
{
    Stack st(10);

    st.push(45);
    st.push(45);
    st.push(45);
    st.push(45);
    st.push(45);
    st.push(45);
    st.push(89);
    st.push(12);
    st.push(23);
    st.push(100);

    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;
   
    cout << st.isFull() << endl;
    cout << st.peek() << endl;

}
