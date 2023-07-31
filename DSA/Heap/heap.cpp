#include <bits/stdc++.h>
using namespace std;

void insertHeap(int arr[], int N, int data)
{
    int index, perindex;
    N++;
    index = N;
    while (index > 0)
    {
        perindex = (index - 1) / 2;
        if (data <= arr[perindex])
            break;
        arr[index] = arr[perindex];
        index = perindex;
    }
    arr[index] = data;
}

void del(int arr[], int N, int *v)
{
    int last, index, left, right;
    *v = arr[0];
    last = arr[N];
    N--;
    index = 0;
    left = 1;
    right = 2;

    while (right <= N)
    {
        if (last >= arr[left] && last >= arr[right])
        {
            arr[index] = last;
            return;
        }
        if (arr[left] >= arr[right])
        {
            arr[index] = arr[left];
            index = left;
        }
        else
        {
            arr[index] = arr[right];
            index = right;
        }
        left = 2 * index + 1;
        right = 2 * index + 2;

        if (left == N && last < arr[left])
        {
            arr[index] = arr[left];
            index = left;
        }
        arr[index] = last;
    }
}

void heapSort(int arr[], int N)
{
    int j, item;
    for (j = 0; j < N - 1; j++)
    {
        insertHeap(arr, j, arr[j + 1]);
    }
    while (N > 0)
    {
        del(arr, N - 1, &item);
        arr[N - 1] = item;
        N--;
    }
}
void showarr(int arr[], int n)
{
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {12, 50, 20, 66, 33, 42, 62, 17, 60, 90};
    heapSort(arr, 10);
    // for (int i = 0; i < 10; i++)
    // {
    //     insertHeap(arr,i,arr[i+1]);
    // }
    // insertHeap(arr, 0, arr[0]);
    showarr(arr, 10);
}