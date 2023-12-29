#include <bits/stdc++.h>  // Merge two Arrays
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void merge(int arr1[],int n,int arr2[],int m,int arr3[])
{
    int i = 0, j = 0,k=0;
    while (i<n && j<m)
    {
        if(arr1[i]<arr2[j])

        {arr3[k++] = arr1[i++];}
        else
        {arr3[k++] = arr2[j++];}
    }

    while (i<n)
        arr3[k++] = arr1[i++] ;

    while (j < m)
        arr3[k++] = arr2[j++] ;
}

void printArr(int arr[],int n)
{
    for (int i = 0; i < n;i++)
    {
        cout << arr[i];
        if(i!=n-1)
            cout << ",";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {2, 5, 7, 9, 11, 13};
    int arr2[] = {1, 3, 10, 12};
    int arr3[10] = {0};

    merge(arr1, 6, arr2, 4, arr3);
    printArr(arr3,10);
    return 0;
}