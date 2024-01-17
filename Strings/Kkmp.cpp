#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pattern, vector<int> &lps)
{
    int M = pattern.length();
    int len = 0; // Length of the previous longest prefix & suffix

    lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]

    int i = 1;
    while (i < M)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string pat, string txt)
{
    int N = txt.length();
    int M = pat.length();
    vector<int> result;

    // Create an LPS array to store the longest proper prefix which is also a suffix
    // lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
    vector<int> lps(M, 0);
    computeLPS(pat, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            result.push_back(i - j); // Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return result;
}
int main()
{

    string txt = "geeksforgeeks";
    string pat = "geeks";
    vector<int> result = search(pat, txt);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}