#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
            cout << ",";
    }
    cout << endl;
}

void shift(int arr[],int n,int k)
{
    int arr2[7];
    for (int i = 0; i <n ; i++)
    {
        arr2[(i + k) % n] = arr[i];
    
    }
    printArr(arr2,n);
}
int main()
{
    int arr[] = {0, 2, 0, 4, 36, 0, 0};
    printArr(arr,7);
    shift(arr, 7, 3);

    return 0;
}