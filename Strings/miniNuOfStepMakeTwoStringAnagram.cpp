#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();

        int mp_s[26] = {0};
        int mp_t[26] = {0};

        for (int i = 0; i < n1; i++)
        {
            mp_s[s[i] - 'a']++;
            mp_t[t[i] - 'a']++;
        }

        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (mp_s[i] > mp_t[i])
            {
                res += mp_s[i] - mp_t[i];
            }
        }

        return res;
    }
};
int main()
{
    string s = "leetcode";
    string t = "practice";
    Solution obj;
    cout << obj.minSteps(s, t) << endl;

    return 0;
}