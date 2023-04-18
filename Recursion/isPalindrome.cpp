#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    if (i > j)
        return true;
    if(str[i] != str[j])
        return false;
    return isPalindrome(str, i + 1, j - 1);
}

int main()
{

    string str = "abcdcbak";

    bool ans = isPalindrome(str, 0, str.length() - 1);

    if (ans)
        cout << "string is palindrome " << endl;
    else
        cout << "string is not a palindrome" << endl;

    return 0;
}