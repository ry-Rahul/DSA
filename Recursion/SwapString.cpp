#include <bits/stdc++.h>
using namespace std;

void reverse(string &s, int i)
{
 
    if(i == s.length())
        return;

    reverse(s, i+1);
// Rahul
// luhaR
    if(i < s.length()/2)
        swap(s[i], s[s.length()-i-1]);
    
}



int main()
{
   string str = "Rahul";
    reverse(str, 0);
    cout<<str;

   return 0;
}