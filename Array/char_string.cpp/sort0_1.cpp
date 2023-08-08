#include <bits/stdc++.h>
using namespace std;

vector<int> sort0_1(vector<int> arr) {
    int start=0,mid;
    int end = arr.size() -1;

    while(start<=end){
        if(arr[start] == 0)
            start++;
        else if(arr[end] ==1)
            end--;
        else{
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    return arr;
}

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
  vector<int> arr = {0,1,1,0,1,1,1,0,1,0,1,1,1,1,0,1};
   
    vector<int> res = sort0_1(arr);
    print(res);

  return 0;
}