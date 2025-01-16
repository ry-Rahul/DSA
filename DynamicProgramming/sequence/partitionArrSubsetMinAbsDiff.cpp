#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

      int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        int k = sum;

        // previous problem subset sum
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // base case
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // base case
        if (nums[0] <= k)
            dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (target >= nums[ind])
                    take = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = take | notTake;
            }
        }

        // dp table is ready now
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        // dp[n-1][col->0.....totalsum]
        int mini = 1e8;
        for (int s1 = 0; s1 <= sum / 2; s1++)
        {
            if (dp[n - 1][s1] == true)
            {
                mini = min(mini, abs((sum - s1) - s1));
            }
        }

        return mini;
    }
};

int main()
{
    //   Input: nums = [3,9,7,3]
    // Output: 2
    // Explanation: One optimal partition is: [3,9] and [7,3].
    // The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

    vector<int> arr = {3, 9, 7, 3};
    Solution s;
    int n = arr.size();
    cout << s.minimumDifference(arr) << endl;

    return 0;
}