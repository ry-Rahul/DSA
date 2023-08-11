#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr){
    
    int n = arr.size();

    for(int i=1 ; i<n; i++){
        int temp = arr[i];
        int j = i-1;

        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else break;
        }

        arr[j+1] = temp;
    }
}

void display(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
   
   vector<int> arr = {23,89,11,10,8,7,3,2,59};

   InsertionSort(arr);

   display(arr);



  return 0;
}