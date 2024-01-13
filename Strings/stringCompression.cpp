#include <bits/stdc++.h>
using namespace std;

// leetcode-443
class Solution
{
public:

   /*
    Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
    */
    int compress(vector<char> &chars)
    {

        int n = chars.size();
        int i = 0;
        int index = 0;

        // loop through the array
        while (i < n)
        {

            // current character
            char curr_char = chars[i];
            int count = 0;

            // count the number of times the current character appears
            while (i < n && curr_char == chars[i])
            {
                count++;
                i++;
            }

            // if the count is greater than 1, then we need to add the count to the array
            chars[index] = curr_char;
            index++;

            // if the count is greater than 1, then we need to add the count to the array
            if (count > 1)
            {
                // convert the count to a string
                string str = to_string(count);
                for (int i = 0; i < str.size(); i++)
                {
                    chars[index] = str[i];
                    index++;
                }
            }
        }

        return index;
    }
};

int main()
{
    /*
    Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
    */

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution s;
    cout << to_string(s.compress(chars)) << endl;

    return 0;
}