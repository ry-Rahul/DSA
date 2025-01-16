#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

// sort the array in the range of k

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> vec;

    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i = 0; i < 7; i++)
    {
        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            vec.push_back(minheap.top());
            minheap.pop();
        }
    }

    while (minheap.size() > 0)
    {
        vec.push_back(minheap.top());
        minheap.pop();
    }

    for (auto it : vec)
    {
        cout << it << " ";
    }

    return 0;
}