#include <bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>> arr)
{
    for (auto it : arr)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "]";
        cout << endl;
    }
}

void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> ds, int freq[])
{
    // Permutation is a subset of Combination
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[i] == 0)
        {
            if (nums[i] == nums[i - 1] && freq[i - 1] == 0)
                continue;
            freq[i] = 1;
            ds.push_back(nums[i]);
            solve(nums, ans, ds, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];

    // memset is used to set the value of the array to a particular value
    memset(freq, 0, sizeof(freq));

    solve(nums, ans, ds, freq);

    printArr(ans);

    return ans;
}
int main()
{

    vector<int> arr = {1, 1, 2};
    permute(arr);

    return 0;
}