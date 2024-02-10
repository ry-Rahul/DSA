#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOpening(char c) { return (c == '(') || (c == '{') || (c == '['); }
    bool isMatching(char c, char peek)
    {
            if(c==')' && peek=='(')
                return true;
            else if(c=='}' && peek=='{')
                return true;
            else if(c==']' && peek=='[')
                return true;
            else
                return false;
    }

    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {

            char c = s[i];


        // if is opening then push to stack
            if (isOpening(c))
            {
                st.push(c);
            }
            // if is closing then check if it matches with top of stack
            else
            {

                // if stack is empty or top of stack is not matching then return false
                if (st.empty())
                {

                    return false;
                }
                else if (!isMatching(c, st.top()))
                {
                    return false;
                }
                else
                    st.pop();
            }
        }

        return st.empty();
    }
};


// approach 2 
bool isValid2(string s) {
    stack<char> st;
    for (char c : s) {
        
        if(c=='(')
            st.push(')');
        else if(c=='{')
            st.push('}');
        else if(c=='[')
            st.push(']');
        else if(st.empty() || st.top()!=c)
            return false;
        else if(st.top()==c)
            st.pop();
    }
    return st.empty();
}
int main()
{

    Solution s;
    cout << s.isValid("()[]{}");
    cout<<endl;


    return 0;
}