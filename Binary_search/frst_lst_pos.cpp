#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

int Fisrt_Occur(int a[], int size, int key)
{
    int mid,ans = -1;
    int end = size - 1;
    int start = 0;
    mid = start + (end - start) / 2;
     while (start <= end)
    {
        if (a[mid] == key)
        {
            ans = mid;
            end = mid-1;
        }
       else if (key > a[mid])
            start = mid + 1;
        else if (key < a[mid])
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}

int last_Occur(int a[], int size, int key)
{
    int mid, ans = -1;
    int end = size - 1;
    int start = 0;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (a[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (key > a[mid])
            start = mid + 1;
        else if (key < a[mid])
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int arr[] = {1,2,3,3,5};
    cout << Fisrt_Occur(arr, 5, 3)<<" ";
    cout << last_Occur(arr, 5, 3);

    return 0;
}