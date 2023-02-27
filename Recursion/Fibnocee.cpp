#include <bits/stdc++.h>
using namespace std;
// F(n) = F(n-1) + F(n-2)
int dp[100];

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    else
    {
        dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return dp[n];
    }
}
int main()
{
    for (int i = 0; i < 100; i++)
        dp[i] = -1;

    int n;
    cout << "Entere a number for fibonacci series:" << endl;
    cin >> n;
    cout << fibonacci(n) << endl;
    // vector<int> v(10);
    // vector<vector<int>> m(vector<);
    // cout << v.size();
    return 0;
}