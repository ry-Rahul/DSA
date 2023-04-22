#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// this is for non repaeting numbers
    void solve(vector<vector<int>> &ans , int index , vector<int> nums){
        if(index>= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            solve(ans,index+1,nums);
            swap(nums[index],nums[i]);
        }

    }
// this  is for repaeting numbers
     void solveRepeat(vector<vector<int>> &ans , int index , vector<int> nums){
        if(index>= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            if(i!=index && nums[i]==nums[index]) continue;
        
            swap(nums[index],nums[i]);
            solveRepeat(ans,index+1,nums);
            swap(nums[index],nums[i]);
        }
     }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        // solve(ans,index,nums);
        solveRepeat(ans,index,nums);
        return ans;
    }
};
int main(){
    vector<int> nums = {1,1,2};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
