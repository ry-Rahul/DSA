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
    int solve(vector<vector<int>> &arr, int ind)
    {
        if (ind >= arr.size())
        {
            return 0;
        }

        int next = findNext(arr, ind + 1, arr[ind][1]);
        int take = arr[ind][2] + solve(arr, next);
        int notTake = solve(arr, ind + 1);

        return max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();

        vector<vector<int>> arr(n, vector<int>(3, 0)); //{s,e,p}
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());

        return solve(arr, 0);
    }
};

int main()
{
    // Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120

    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};

    Solution s;
    cout << s.jobScheduling(startTime, endTime, profit)<<endl;

    return 0;
}