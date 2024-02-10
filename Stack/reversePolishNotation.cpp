#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int operate(int a,int b, string token){
        if(token=="+") return a+b;
        if(token=="-") return a-b;
        if(token=="*") return a*b;
        if(token=="/") return a/b;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &it:tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){

                int b=st.top();
                st.pop();

                int a= st.top();
                st.pop();

                int res=operate(a,b,it);
                st.push(res);
            }else{
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};
int main(){
  

  return 0;
}