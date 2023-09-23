#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i , int j,vector<vector<int>> dp){
        if(i==0 && j ==0 ) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(i-1, j,dp);
        int left = solve(i, j-1, dp);

        return dp[i][j]=up+left;
    }


    int uniquePaths(int m, int n) {
        
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);

        int dp[m][n];
        for(int i = 0; i<m ; i++){

            for(int j = 0; j<n; j++){
                if(i==0 ||  j==0)
                   dp[i][j]=1;
                else{
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){

//     Input: m = 3, n = 7
//     Output: 28

    Solution s;
    cout<<s.uniquePaths(3,7)<<endl;

    return 0;
}