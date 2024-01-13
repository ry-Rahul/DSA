#include <bits/stdc++.h>
using namespace std;

bool isCapital(string str){
    
    int n = str.size();
    string temp = str;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    if (temp == str) return true;
    return false;
}
bool isSmall(string str)
{

    string temp = str;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    cout << temp << endl;

    if (str == temp)
    {
        return true;
    }

    return false;
}
bool detectCapital(string str)
{
    int n = str.size();

    if (isCapital(str) || isSmall(str) || (isSmall(str.substr(1)) && isCapital(str.substr(0,1))))
    {
        return true;
    }
    return false;
}
int main()
{
    string str = "Leetcode";
    cout << detectCapital(str) << endl;
    // cout<<isCapital(str)<<endl;

    return 0;
}