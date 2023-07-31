#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

// find the kth largest element from array 7 10 4 3 20 15
// output = 20 15 10
int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        min_heap.push(arr[i]);
        if (min_heap.size() > k)
        {
            // cout << min_heap.top()<<" ";
            min_heap.pop();
        }
    }
    cout << endl
         << "size of min Heap = " << min_heap.size() << endl;
    while (min_heap.size() > 0)
    {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }

    return 0;
}