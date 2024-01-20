#include <bits/stdc++.h>
using namespace std;

// leetcode 402

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        int digit = num.size() - k;
        if (num.size() <= k)
        {
            return "0";
        }

        int top = -1;
        int start = 0;

        for (int i = 0; i < num.size(); i++)
        {
            while (top >= 0 && num[top] > num[i] && k > 0)
            {
                top--;
                k--;
            }
            top++;
            num[top] = num[i];
        }

        while (start <= top && num[start] == '0')
            start++;
        string ans = "";

        for (int i = start; i < digit; i++)
        {
            ans += num[i];
        }

        if (ans == "")
            return "0";
        return ans;
    }
};
int main()
{

    string num = "1432219";
    int k = 3;
    Solution obj;
    string ans = obj.removeKdigits(num, k);
    cout << ans << endl;

    return 0;
}