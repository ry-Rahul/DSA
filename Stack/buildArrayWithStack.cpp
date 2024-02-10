#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {

        int stream = 1;
        int i = 0;
        vector<string> ans;

        while (stream <= n && i < target.size())
        {
            ans.push_back("Push");

            if (stream == target[i])
            {
                i++;
            }
            else
            {
                ans.push_back("Pop");
            }

            stream++;
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {1, 3};
    vector<string> ans = s.buildArray(arr, 3);

    for (string s : ans)
    {
        cout << s << " ";
    }



    return 0;
}