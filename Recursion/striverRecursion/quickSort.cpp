#include <bits/stdc++.h>
using namespace std;

// printArray
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//correctPlace
int correctPlace(int arr[], int st, int end){
    int pivot = arr[st];

    int i = st;
    int j = end;       

    // 4, 6, 2, 5, 7, 9, 1, 3

    // 4, 6, 9, 5, 7, 2, 1, 3

    while(i<j){
          while(arr[i]<=pivot && i<end){
            i++;
        }
        while(arr[j]>pivot && j>st){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
            // printArray(arr, 8);
        }
    }

    swap(arr[st], arr[j]);
    
    return j;
}
void quickSort(int arr[], int st, int end){

    if(st<end){
        int partition = correctPlace(arr, st, end);
        quickSort(arr, st, partition-1);
        quickSort(arr, partition+1, end);
    }
}
int main()
{

    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout<<endl;

    return 0;
}