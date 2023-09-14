#include <bits/stdc++.h>
using namespace std;

vector<int> findPivot(vector<int> arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = 0;

    while(s<e){
        mid = s + (e-s)/2;

        if(arr[mid]>arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return {s,arr[s]};
}

void printArr(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
  vector<int> arr = {6,7,8,9,10,20,3};

  vector<int> ans = findPivot(arr);
  printArr(ans);

  return 0;
}