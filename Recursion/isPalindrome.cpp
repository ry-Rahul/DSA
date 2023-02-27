#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    if (i < j)
    {
        if (str[i++] == str[j--])
            return true && isPalindrome(str, i, j);
        else
            return false;
    }
    return true;
}

int main()
{

    string str = "wasdsae";

    bool ans = isPalindrome(str, 0, str.length() - 1);

    if (ans)
        cout << "string is palindrome " << endl;
    else
        cout << "string is not a palindrome" << endl;

    return 0;
}