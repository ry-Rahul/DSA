#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int sum, vector<int> &nums)
{

    if (sum == 0)
        return 1;
    if (ind == 0)
        return sum == nums[0];

    int notTake = solve(ind - 1, sum, nums);
    int take = 0;
    if (sum >= nums[ind])
        take = solve(ind - 1, sum - nums[ind], nums);

    return take + notTake;
}
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    return solve(n - 1, k, nums);
}
int main()
{

    vector<int> v = {1, 2,1,6,3};
    int k = 6;

    cout << subarraySum(v, k);
    cout << endl;

    return 0;
}