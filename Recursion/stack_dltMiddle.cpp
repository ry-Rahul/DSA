#include <bits/stdc++.h>
using namespace std;

stack<int> solve(stack<int> &s,int k)
{
       if(k==1)
       {
           s.pop();
           return s;
       }
       else{
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