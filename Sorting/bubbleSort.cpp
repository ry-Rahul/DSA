#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr){
    int n = arr.size();
    bool flag = false;

    for(int i = 0; i<n-1; i++){
        flag = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
            // cout<<"loop"<<endl;
        }
        if(flag == false){
            break;
        }
    }
}

int main(){

    vector<int> arr = {78,12,45,98,56,23,11};
    // vector<int> arr = {1,2,3,4,5,6};

    BubbleSort(arr);

    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

  

  return 0;
}