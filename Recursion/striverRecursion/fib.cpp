#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){

    int n=4;
    cout<<"Entere a number for fibonacci series:"<<endl;
    // cin>>n;
    cout<<fibonacci(n)<<endl;
    // vector<int> v(10);
    // vector<vector<int>> m(vector<);
    // cout << v.size();
  

  return 0;
}