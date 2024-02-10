#include <bits/stdc++.h>
using namespace std;

/* Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4 */
int solve(int n,vector<int>&dp){
    if(n==0) return 1;

    if(dp[n]!=-1) return dp[n];

    int ans = 0;

    for(int i=1;i<=6;i++){
        if(i>n) break;
        (ans += solve(n-i,dp))%=1000000007;
    }

    return dp[n] = ans;
}
int main(){

    int n;
    cin >> n;
    int mod = 1e9+7;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j>i) break;
            (dp[i] += dp[i-j])%=mod;
        }
    }
    cout << dp[n] << endl;

    return 0;
}