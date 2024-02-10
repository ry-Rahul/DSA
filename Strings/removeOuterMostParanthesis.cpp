#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string str="";

        for(int i=0;i<s.length(); i++){ 

            if(s[i]=='('){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt==1 && s[i]=='(' || cnt==0 && s[i]==')'){
                continue;
            }

            str+=s[i];
        }
        return str;
    }
};
int main(){

//     Input: s = "(()())(())"
// Output: "()()()"

    // string s = "(()())(())";
    string s = "(()())(())(()(()))";
    Solution obj;
    cout<<obj.removeOuterParentheses(s);
    cout << endl;

    return 0;
}