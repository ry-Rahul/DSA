#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
            string words;
            string ans = "";
            stringstream ss(s);

            while (ss >> words)
            {
                if (ans != "")
                {
                    ans = words + " " + ans;
                }
                else
                {
                    ans = words + ans;
                }
            }

            return ans;
        
    }
};
int main()
{

    string s = "the sky is blue";
    Solution obj;
    cout << obj.reverseWords(s);
    cout << endl;

    return 0;
}