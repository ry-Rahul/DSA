#include <bits/stdc++.h>
using namespace std;


 void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds,int ind){
        ans.push_back(ds);
        for(int i=ind; i<nums.size(); ++i){
            if(i!=ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            solve(nums,ans,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // set<vector<int>> ans;
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        solve(nums,ans,ds,0);

        // for(auto &it : ans){
        //     temp.push_back(it);
        // }

        for(auto &it : ans){
            for(auto &i : it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return ans;

    }
int main()
{

    vector<int> arr = {1, 2, 2};
    int N = 3;
    subsetsWithDup(arr);

    return 0;
}
