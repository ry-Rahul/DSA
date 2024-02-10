#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n,int dp[]){
        if(n<=0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }
        int minCnt=1e5;

        for(int i=1; i*i <= n ; i++){
            int result = 1 + solve(n-i*i,dp);

            minCnt=min(minCnt,result);
        }

        return dp[n]=minCnt;
    }
    int numSquares(int n) {
        int dp[10001];
        memset(dp,-1,sizeof(dp));
        return solve(n,dp);
    }
};
int main(){

    Solution s;
    cout<<s.numSquares(12);
    
  

  return 0;
}