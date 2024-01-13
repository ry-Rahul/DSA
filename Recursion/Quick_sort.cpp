#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end)
{

    int pivot, pivotIndex, count = 0;
    pivot = arr[start];

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= arr[pivot])
            count++;
    }

    // place pivot at right position
    pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // left and right wala part sambhal lete hai
    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {

            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quick_sort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    // left array sort
    if (p > start + 1)
        quick_sort(arr, start, p - 1);

    // right array
    if (p < end - 1)
        quick_sort(arr, p + 1, end);
}

void printArr(int *arr, int n)
{
    cout<<"[";
    for (int i = 0; i < n; i++)
        if (i != n - 1)
            cout << arr[i] << ",";
        else
            cout << arr[i];
    cout<<"]\n";
}

int main()
{
    int arr[] = {8, 9, 10, 87, 36, 66, 12, 2, 1, 1, 1, 55};

    printArr(arr, 12);
    quick_sort(arr, 0, 11);
    printArr(arr, 12);

    return 0;
}