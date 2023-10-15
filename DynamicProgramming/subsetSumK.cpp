#include <bits/stdc++.h>
using namespace std;


bool solve(int ind, int target , vector<int>  arr,vector<vector<int>> &dp){

      if(target==0)
          return true;
       if(ind==0)
          return target == arr[0];
        if(dp[ind][target]!=-1)
            return dp[ind][target];

       bool notTake = solve(ind-1, target, arr,dp);
       bool take = false;
         if(target>=arr[ind])
            take = solve(ind-1, target-arr[ind], arr,dp);

         return  dp[ind][target] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>> dp(n, vector<int>(k+1, -1));
    //  return solve(n-1, k, arr,dp);

    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i = 0; i<n; i++){
        dp[i][0] = true;
    }

    if(arr[0]<=k)
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool notTake = dp[ind - 1][tar];
            bool take = false;
            if (tar >= arr[ind])
                take = dp[ind - 1][tar - arr[ind]];

            dp[ind][tar] = take | notTake;
        }
    }

    //print dp array
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n - 1][k];
}


int main(){
  
  vector<int> arr = {4, 3, 2, 1};
  int target = 5;
    cout<<subsetSumToK(arr.size(), target, arr)<<endl;

  return 0;
}