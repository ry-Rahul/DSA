#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<string> &ds,int n, int op ,int cl,string str){

         if(op==cl && op==n && cl==n){
             ds.push_back(str);
             return ;
         }

         if(op==cl){

            solve(ds,n,op+1,cl,str+"(");
         }else{
             if(op<n){
                 solve(ds,n,op+1,cl,str+"(");
                 solve(ds,n,op,cl+1,str+")");
             }else{
                 solve(ds,n,op,cl+1,str+")");
             }
         }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ds;
        solve(ds,n,0,0,"");
        return ds;
    }
};
int main(){
  
    Solution s;
    vector<string> ds = s.generateParenthesis(3);
    for(auto it:ds){
        cout<<it<<endl;
    }

  return 0;
}