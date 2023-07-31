// #include <bits/stdc++.h>
// using namespace std;
// class Stack
// {
// public:
//     int size;
//     int *arr;
//     int top;

//     Stack(int size)
//     {
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }

//     void push(int data);
//     void pop();
//     int peek();
//     bool isEmpty();
//     bool isFull();
// };
// void Stack::push(int data)
// {
//     if (size - top > 1)
//     {
//         top++;
//         arr[top] = data;
//     }
//     else
//     {
//         cout << "Stack overflow" << endl;
//     }
// }
// void Stack::pop()
// {
//     if (top >= 0)
//         top--;
//     else
//         cout << "stack underflow" << endl;
// }
// int Stack::peek()
// {
//     if (top >= 0)
//         return arr[top];
//     else
//         return -1;
// }

// bool Stack::isEmpty()
// {
//     if (top < 0)
//         return true;
//     else
//         return false;
// }

// bool Stack::isFull()
// {
//     if (top == size - 1)
//         return true;
//     else
//         return false;
// }


// int main()
// {
//     Stack st(10);
  
// }



// --------------Recursion----------------
#include <bits/stdc++.h>
using namespace std;

stack<int> solve(stack<int> &s, int k)
{
    if (k == 1)   // k ki smallest value 1 
    {
        s.pop();
        return s;
    }
    else
    {
        int temp = s.top();
        s.pop();
        solve(s, k - 1);
        s.push(temp);
        return s;
    }
}
stack<int> dltMiddle(stack<int> &s)
{
    int k = (s.size() / 2) + 1;
    if (s.size() == 0)
        return s;
    solve(s, k);
    return s;
}

void printstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    stack<int> s;
    int n = 10;
    while (n--)
    {
        s.push(1 + rand() % 100);
    }
    printstack(s);
    dltMiddle(s);
    printstack(s);

    return 0;
}