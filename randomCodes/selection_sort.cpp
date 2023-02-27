#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int i, j, minindex;
    int arr[] = {14, 99, 45, 15, 28, 1, 2, 4, 2};
    for (i = 0; i < 8; i++)
    {
        minindex = i;
        for (j = i + 1; j < 9; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        swap(arr[minindex], arr[i]);
    }

    for (i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}