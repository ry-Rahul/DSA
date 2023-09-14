#include <bits/stdc++.h>
using namespace std;


int solve(int ind, vector<int> &heights , vector<int> &dp){
    // Write your code here.
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int left = solve(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right =INT_MAX;
    if(ind>1)
       right = solve(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    
    return dp[ind]=min(left,right);
}


int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n+1,-1);
    // return solve(n-1, heights,dp);


    //Tabulation approach
    /*
    
    vector<int> dp(n+1,0);
    dp[0] = 0;

    for(int i = 1; i<n; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2] + abs(heights[i]-heights[i-2]);
        
        dp[i] = min(left,right);
    }

    return dp[n - 1];

    */



    //Optiaml Tabulation approach
    int prev1 = 0;
    int prev2 = 0;

    for(int i = 1; i<n; i++){
        int left = prev1 + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = prev2 + abs(heights[i]-heights[i-2]);
        
        int  curr = min(left,right);

        prev2 = prev1;
        prev1 = curr;

    }

    return prev1;


    
}


int main(){

    int n = 4;
    vector<int> heights = {10,20,30,10};
    cout<<frogJump(n,heights)<<endl;
  
  return 0;
}
