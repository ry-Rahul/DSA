#include <bits/stdc++.h>
using namespace std;

void reverse_str(string &str,int i,int j)
{

    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    reverse_str(str, i, j);
}

int main()
{
    string str;
    getline(cin, str);
    reverse_str(str, 0, str.length() - 1);
    cout << str;

    return 0;
}

