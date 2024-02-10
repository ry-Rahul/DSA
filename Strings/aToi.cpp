#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {

        int n = s.size();
        long res = 0;
        int i = 0;

        // remove spaces
        while (i < n && s[i] == ' ')
            i++;

        int sign = 1;
        // check sign
        if (i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+')
        {
            i++;
        }

        // check for digits
        int MAX = INT_MAX;
        int MIN = INT_MIN;

        while (i < n)
        {
            // if digit is not found
            if (s[i] == ' ' || !isdigit(s[i]))
            {
                break;
            }

            // if digit is found
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {

                res = res * 10 + (s[i] - '0');

                if (res * sign > MAX)
                {
                    return MAX;
                }
                if (res * sign < MIN)
                {
                    return MIN;
                }
            }

            i++;
        }

        return res * sign;
    }
};
int main()
{

    string s = "   -42";
    Solution obj;
    cout << obj.myAtoi(s);
    cout << endl;

    return 0;
}