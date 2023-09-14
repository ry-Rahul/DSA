#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){

    //time complexity: O(n)
    //space complexity: O(n)
    if(n<=1){
        return n;
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

// int fib(int n){
  
//      if(n<=1){
//         return n;
//      }

//     return fib(n-1) + fib(n-2);
// }

int fib2(int n){
    int curr = 0;
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main(){
  int n=30;
  vector<int> dp(n+1,-1);

  cout<<fib(n,dp)<<endl; 
    cout<<fib2(n)<<endl;


  return 0;
}