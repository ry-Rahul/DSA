#include <bits/stdc++.h>
using namespace std;
// 1154 leetcode
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {

        // string ans = "";

        // for (char i:s){

        //     if (ans.back() + 32 == i || ans.back() - 32 == i){
        //         ans.pop_back();
        //     }
        //     else{
        //         ans.push_back(i);
        //     }
        // }

        string ans = "";
        stack<char> st;
        for (char i : s)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                if (st.top() + 32 == i || st.top() - 32 == i)
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.makeGood("leEeetcode") << endl;
    cout << s.makeGood("abBAcC") << endl;
    cout << s.makeGood("s") << endl;

    return 0;
}
