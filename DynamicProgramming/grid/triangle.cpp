#include <bits/stdc++.h>
using namespace std;

int solve(int i ,int j, vector<vector<int>> &tri, int n ,vector<vector<int>> &dp){

    if(i==n-1) return tri[n-1][j];
    if(i<0 || j<0 || i>=n || j>=n) return 1e9;
    if(dp[i][j]!=0) return dp[i][j];
 
    int left = tri[i][j] + solve(i+1, j, tri, n,dp);
    int right = tri[i][j] + solve(i+1, j+1, tri, n,dp);

    return dp[i][j]=min(left, right);

    }
int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return solve(0,0 , triangle,n,dp);

        // Bottom up approach
        for (int i = 0; i<n ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<=i; j++){
                int left = triangle[i][j] +dp[i+1][j] ;
                int right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(left, right);
            }
        }
        return dp[0][0];
}

int main(){
  
//   Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
    
        vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
        cout<<minimumTotal(triangle)<<endl;

  return 0;
}