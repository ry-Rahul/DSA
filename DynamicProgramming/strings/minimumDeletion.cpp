#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &str1, string &str2){
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        return (n + m - 2 * lcs(word1, word2));
    }
};
int main()
{
    /*Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 */
    string word1 = "sea";
    string word2 = "eat";
    Solution s;
    cout << s.minDistance(word1, word2) << endl;

    return 0;
}