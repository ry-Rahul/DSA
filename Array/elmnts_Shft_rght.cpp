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

int main()
{
    int arr[] = {0, 2, 0, 4, 36, 0, 0};

    printArr(arr, 7);

    int notZero=0;
    for (int i = 0; i <7 ; i++)
    {
        if(arr[i]!=0){
            swap(arr[i], arr[notZero]);
        notZero++;
        }
    }
    printArr(arr, 7);


    int n = 0,j=0,u=6;
    for (int j = 0; j < 7; j++)
    {
        if (arr[j] == 0)
        {
            swap(arr[j], arr[n++]);
            
        }
    }
    printArr(arr, 7);

    return 0;
}