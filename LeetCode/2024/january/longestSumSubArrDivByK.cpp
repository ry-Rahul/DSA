#include <bits/stdc++.h>
using namespace std;

int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // Complete the function
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int rem = sum % k;
        if (rem < 0)
        {
            rem += k;
        }
        if (rem == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (mp.find(rem) != mp.end())
        {
            ans = max(ans, i - mp[rem]);
        }
        else
        {
            mp[rem] = i;
        }
    }
    return ans;
}
int main()
{

    // N = 6, K = 3
    // arr[] = {2, 7, 6, 1, 4, 5}
    // Output: 4
    // 7, 6, 1, 4

    int arr[] = {2, 7, 6, 1, 4, 5};
    int k = 3;
    cout << longSubarrWthSumDivByK(arr, 6, k) << endl;

    return 0;
}