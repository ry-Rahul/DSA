#include <bits/stdc++.h>
using namespace std;

// 899 leetcode

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {

        int n = s.size();
        string ans;
        string temp = s;

        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }

        for (int i = 1; i < n; i++)
        {
            ans = s.substr(i) + s.substr(0, i);
            temp = min(ans, temp);
        }
        return temp;
    }
};
int main()
{
//     Input: s = "baaca", k = 3
// Output: "aaabc"
    Solution s;
    cout << s.orderlyQueue("baaca", 3) << endl;
    cout << s.orderlyQueue("cba", 1) << endl;

    return 0;
}