#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int ind)
    {
        // if(ind==nums.size()){
        //     ans.insert(ds);
        //     return;
        // }
        // ds.push_back(nums[ind]);
        // solve(nums,ans,ds,ind+1);
        // ds.pop_back();

        ans.push_back(ds);

        for (int i = ind; i < nums.size(); ++i)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            solve(nums, ans, ds, i + 1);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // set<vector<int>> ans;
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        solve(nums, ans, ds, 0);

        // for(auto &it : ans){
        //     temp.push_back(it);
        // }
        return ans;
    }
};
int main()
{
    // Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    vector<int> arr = {1, 2, 2};
    Solution s;
    vector<vector<int>> ans = s.subsetsWithDup(arr);
    for (auto it : ans){
        for (auto ele : it)
           cout << ele << " ";
        cout << endl;
    }

    return 0;
}