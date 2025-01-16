#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string str,vector<string>&ans,int ind){
        
        if(str.size()==ind){
            ans.push_back(str);
            
            return;
        }
        for(int i=ind; i<str.size(); i++){
            swap(str[i],str[ind]);
            solve(str,ans,ind+1);
            swap(str[i],str[ind]);
        }
    }
    string getPermutation(int n, int k) {
        vector<string> ans;
        int l=n; 
        string str="";
        for(int i=1; i<=n; i++){
            str+=to_string(i);
        }
        solve(str,ans,0);

        //    print ans
        // for(auto it:ans){
        //     cout<<it<<" "<<endl;
        // }
        sort(ans.begin(),ans.end());
       
        return ans[k-1];
    }
};
int main(){

    Solution s;
    cout<<s.getPermutation(3,3)<<endl;
  

  return 0;
}