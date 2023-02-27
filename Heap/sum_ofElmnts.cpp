#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

// find the sum of elements between k1th smallest and k2th smallest elements

int findKthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

int main()
{
    int arr[] = {1, 3, 5, 11, 12, 15};
    int k1 = 3, k2 = 6;
    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int first = findKthSmallest(arr, n, k1);
    int second = findKthSmallest(arr, n, k2);

    for (int i = 0; i < n; i++)
    {
        if (first < arr[i] && arr[i] < second)
        {
            sum = sum + arr[i];
        }
    }
    cout << sum;
    return 0;
}