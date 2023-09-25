#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {

        // vector to store the frequency of each character
        vector<int> freq(26, 0);

        // loop through the string and update the frequency of each character in the vector
        for (int i = 0; i < sentence.size(); i++)
        {
            freq[sentence[i] - 'a']++;
        }

        // if any character has a frequency of 0, then return false
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
            {
                return false;
            }
        }

        // otherwise return true
        return true;
    }
};
int main()
{

    /*
    Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
    */

    // string sentence = "thequickbrownfoxjumpsoverthelazydog";
    string sentence = "leetcode";
    Solution s;
    cout << s.checkIfPangram(sentence) << endl;

    return 0;
}