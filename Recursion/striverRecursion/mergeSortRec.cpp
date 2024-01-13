#include <bits/stdc++.h>
using namespace std;

// mergeArray
void mergeArray(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int start = low;
    int end = mid + 1;

    while(start<=mid && end<=high){
        if(arr[start]<arr[end]){
            temp.push_back(arr[start]);
            start++;
        }
        else{
            temp.push_back(arr[end]);
            end++;
        }
    }

    while(start<=mid){
        temp.push_back(arr[start]);
        start++;
    }

    while(end<=high){
        temp.push_back(arr[end]);
        end++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
// mergeSortRec
void mergeSortRec(int arr[], int low, int high)
{

    if (low == high)
    {
        return;
    }
    int mid = low + (high - low) / 2;

    mergeSortRec(arr, low, mid);
    mergeSortRec(arr, mid + 1, high);

    mergeArray(arr, low, mid, high);
}
// printArr
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[i];
        }
    }
    cout << endl;
}

int main()
{

    // int arr[] = {3, 1, 2, 4, 1, 5, 6, 2, 4};
    int arr[] = {1,2,3,4,1,2,4,5,6};
    // mergeSortRec(arr, 0, 8);
    mergeArray(arr, 0, 3, 8);
    printArr(arr, 9);

    return 0;
}