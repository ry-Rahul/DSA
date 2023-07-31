#include <bits/stdc++.h>
using namespace std;

void insertTemp(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();

    insertTemp(s, temp);
    s.push(val);

    // return;
}

void sortstack(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();

    sortstack(s);
    insertTemp(s, temp);

     
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

    for (int i = 0; i < 10; i++)
    {
        s.push(35+ rand() % 46);
    }

    printstack(s);
    sortstack(s);
    printstack(s);
}

/*
Example :

    random integers between 35 and 42 inclusive

    int num = 35 + rand() % 8;

*/
