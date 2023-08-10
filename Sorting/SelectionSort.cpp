#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
  vector<int> arr = {34,67,12,89,45,23,9,66,77,88,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114};

    selectionSort(arr);

    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



  return 0;
}