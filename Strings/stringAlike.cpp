#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {

        int n = s.size();
        // n=4
        //  k=2
        int k = n / 2;
        int left_vowel = 0;
        int right_vowel = 0;

        for (int i = 0; i < n; i++)
        {

            if (i < k)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                {
                    left_vowel++;
                }
            }
                
                else if (i >= k)
                {
                    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                    {
                        right_vowel++;
                    }
                }
            
        }

        if (left_vowel == right_vowel)
            return true;
        else
            return false;
    }
};
int main()
{ 


    //     Input: s = "book"
    // Output: true

    string str;
    str = "book";
    Solution s;
    cout << s.halvesAreAlike(str) << endl;

    return 0;
}