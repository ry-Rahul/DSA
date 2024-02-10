#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int k = num.size();

        // we are searching from last
        for (int i = k - 1; i >= 0; i--)
        {

            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};
int main()
{
    string s = "42306";
    Solution obj;
    cout << obj.largestOddNumber(s);
    cout << endl;

    return 0;
}