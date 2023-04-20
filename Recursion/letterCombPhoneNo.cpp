#include <bits/stdc++.h>
using namespace std;

class solution{
    public:

    void solve(string digits, string output, int index, vector<string>& ans, string map[]){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index]-'0';
        string value = map[number];

        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, map);
            output.pop_back();
        
        }
    }
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        string output = "";
        string mapping[10] ={"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        int index = 0;
        solve(digits, output,index, ans, mapping);
        return ans;
    }
};
int main()
{
    string digits = "29";
    solution s;
    vector<string> ans = s.letterCombinations(digits);
    for(auto i: ans){
        cout<<i<<" ";
    }
  return 0;
}