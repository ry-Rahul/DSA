#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

int mountain(int a[], int size)
{
    int mid;
    int end = size - 1;
    int start = 0;
    mid = start + (end - start) / 2;
    while (start < end)
    {
        if (a[mid] < a[mid+1])
        {
            start = mid + 1;
        }
        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    int arr[] = {0,1,2,5,3,1,0};
    cout <<mountain(arr, 7) << " ";

    return 0;
}