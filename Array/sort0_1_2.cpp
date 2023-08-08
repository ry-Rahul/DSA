#include <bits/stdc++.h>
using namespace std;

vector<int> sort0_1_2(vector<int> arr){

    int mid = 0 ;
    int start = 0;
    int end = arr.size()-1;

    while(mid<=end){
        if(arr[mid] == 0){
            swap(arr[mid],arr[start]);
            start++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[end]);
            end--;
        }
    }
    return arr;
}

void printArr(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
  vector<int> arr = {0,1,1,0,1,1,1,0,2,0,2,1,2,1,0,0,1,0,2,2};

  vector<int> res = sort0_1_2(arr);
    printArr(res);

  return 0;
}