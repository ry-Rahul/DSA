#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {

        int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ans = "";
        int rem = 0;

        for (int i = 0; i< 13; i++){
            rem = num / arr[i];
            // cout<<rem<<" ";
            num = num % arr[i];
            while (rem--){
                ans += symbols[i];
            }
        }

            return ans;
    }
};

int main()
{

    //   Input: num = 58
    // Output: "LVIII"
    // Explanation: L = 50, V = 5, III = 3.

    int num = 3;
    Solution s;
    cout << s.intToRoman(num) << endl;

    return 0;
}