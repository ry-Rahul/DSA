#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNext(vector<vector<int>> &arr, int st, int currEndJob)
    {
        int n = arr.size();
        int end = n - 1;
        int res = n + 1;
        int mid = -1;

        while (st <= end)
        {
            mid = st + (end - st) / 2;
            if (arr[mid][0] >= currEndJob)
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return res;
    }

    int solve(vector<vector<int>> &arr, int ind, int dp[])
    {
        if (ind >= arr.size())
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        int next = findNext(arr, ind + 1, arr[ind][1]);
        int take = arr[ind][2] + solve(arr, next, dp);
        int notTake = solve(arr, ind + 1, dp);

        return dp[ind] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        int dp[5001];
        memset(dp, -1, sizeof(dp));

        vector<vector<int>> arr(n, vector<int>(3, 0)); //{s,e,p}
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());

        return solve(arr, 0, dp);
    }
};
int main()
{
    // Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
    vector<int> startTime = {1, 2, 3, 4, 6};
    vector<int> endTime = {3, 5, 10, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};

    Solution s;
    cout << s.jobScheduling(startTime, endTime, profit) << endl;

    return 0;
}