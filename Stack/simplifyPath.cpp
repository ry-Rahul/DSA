#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string token="";

        int n=path.size();
        stringstream ss(path);
        while(getline(ss,token,'/')){
            
            if(token=="" || token==".") continue;

            if(token!=".."){
                st.push(token);
            }else if(!st.empty()){
                st.pop();
            }
        }

        string ans="";
        if(st.empty()) return "/";


        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }

        return ans;
    }
};


int main(){

    Solution s;
    string str="/a/./b/../../c/";
    cout<<s.simplifyPath(str)<<endl;
  

  return 0;
}