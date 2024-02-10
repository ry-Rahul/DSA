#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{

    int n = num.length();
    if (n == k)
        return "0";
    if(k>n)
        return "0";
    
    stack<char> st;
    int i = 0;

    for(int i=0;i<n;i++)
    {
        while (k > 0 && !st.empty() && st.top() > num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while (k > 0)
    {
        st.pop();
        k--;
    }

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    while (ans.length() > 1 && ans[0] == '0')
    {
        ans.erase(ans.begin());
    }

    return ans;


}
int main()
{

    string str="112";
    int k=1;
    cout<<removeKdigits(str,k)<<endl;

    return 0;
}