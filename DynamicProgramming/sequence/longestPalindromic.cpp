#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[1001][1001];
    bool solve(string &str, int i, int j)
    {
        if (i >= j)
        {
            return 1;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }

        if (str[i] == str[j])
        {
            return t[i][j] = solve(str, i + 1, j - 1);
        }

        return t[i][j] = 0;
    }
    string longestPalindrome(string s)
    {

        memset(t, -1, sizeof(t));
        int startingPoint = 0;
        int maxSize = INT_MIN;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (solve(s, i, j))
                {
                    if ((j - i + 1 > maxSize))
                    {
                        maxSize = j - i + 1;
                        startingPoint = i;
                    }
                }
            }
        }

        return s.substr(startingPoint, maxSize);
    }
};
int main()
{

    Solution obj;
    cout << obj.longestPalindrome("babad");
    cout << endl;
    return 0;
}