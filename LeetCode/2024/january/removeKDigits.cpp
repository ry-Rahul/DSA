#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string removeKdigits(string num, int k) {
        int digits = num.size() - k;
        // if(digits<k){
        //     return "0";
        // }
        int top = -1;
        int start = 0;

        string st = num;
        // 1 0 0 2 3 4
        // k =1
        // 0 0 2 3 4 for remove extra zeroes from start of the string that's why we are using start variable
        for(int i = 0; i<st.size(); i++){
            while(top>=0 && st[i]<st[top] && k>0){
                top--;
                k--;
            }
            top++;
            st[top] = st[i];
        }
        // cout<<st<<endl;
        while(start<=top && st[start]=='0'){
            start++;
        }

        string res = "";
        for(int i = start; i<digits; i++){
            res+=st[i];
        }
        if(res==""){
            return "0";
        }
        return res;
    }
};
int main(){

    string num = "149811";
    int k = 3;
    Solution s;
    cout<<s.removeKdigits(num,k)<<endl;
  

  return 0;
}