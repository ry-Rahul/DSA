#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<int> ans;
    // 0  1  2  3  4  5  6  7  8  9  10   11
    // a  b  x  a  b  c  y  h  g  a   b   c
    // a  c  b

    // i=0 -> 10
    // n=12   m = 3
    for (int i = 0; i < n - m + 1; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
        }
        if (j == m)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}


int main()
{

    // string str1 = "abxabcyhgabc";
    string str1 = "geeksforgeeks";
    // string str2 = "abc";
    string str2 = "geek";

    vector<int> ans = bruteForce(str1, str2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}