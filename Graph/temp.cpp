#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& ans,vector<int> ds, vector<int>arr,vector<int> &freq){
        if(ds.size()==arr.size()){
            ans.push_back(ds);
            return ;
        }
        
        for(int i=0; i<arr.size(); i++){
            if(freq[i]==0){
                
                if(i>0 && arr[i]==arr[i-1]&& freq[i-1]==0){
                    continue;
                }
                freq[i]=1;
                ds.push_back(arr[i]);
                solve(ans,ds,arr,freq);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(n,0);
        solve(ans,ds,arr,freq);
        return ans;
        
    }
int main(){

    vector<int> arr = {1,2,1};
    vector<vector<int>> ans = uniquePerms(arr,3);
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
  

  return 0;
}