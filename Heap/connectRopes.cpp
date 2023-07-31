#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)



int main()
{
    int arr[] = {4,3,2,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a, b, sum = 0,cost=0;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
    }

    while (minheap.size()>1)
    {
          a = minheap.top();
             minheap.pop();
          b = minheap.top();
             minheap.pop();

             sum =sum +  a + b;
             cout << sum << " ";
             minheap.push(a + b);
             
    }

    cout << endl<< "minimum cost is " << sum;

    return 0;
}