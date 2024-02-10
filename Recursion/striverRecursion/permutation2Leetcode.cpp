#include <bits/stdc++.h>
using namespace std;

// uniques permutations
 void solve( vector<int> nums, vector<vector<int>> &ans,int index){
         if(index>=nums.size()){
             ans.push_back(nums);
             return;
         }
      
        unordered_set<int> s;
         for(int i = index; i<nums.size();i++){
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
             swap(nums[i],nums[index]);
             solve(nums, ans, index+1);
             swap(nums[i],nums[index]);
         }

     }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
         vector<vector<int>> ans;
        int index = 0;
        solve(arr,ans,index);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
int main()
{

    vector<int> nums = {1,2,1};
    vector<vector<int>> ans = uniquePerms(nums,3);
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}