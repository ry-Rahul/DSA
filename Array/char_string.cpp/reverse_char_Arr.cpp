// Pallindrom

#include <bits/stdc++.h>
using namespace std;

char toLower(char ch)
{
    if(ch>='a' && ch<='z')
        return ch;
    else{
        char temp;
        temp = ch - 'A' + 'a';
        return temp;
    }
}
int getlength(char ch[])
{
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
void reverse(char ch[])
{
    int st = 0;
    int e = getlength(ch) - 1;
    while (st <= e)
    {
        swap(ch[st++], ch[e--]);
    }
}
bool palindrom(char ch[])
{
    int st = 0;
    int en = getlength(ch) - 1;
    while (st<=0)
    {
        if(toLower(ch[st++])!=toLower(ch[en--]))
            return false;
    }
    return true;
}
int main()
{
    char ch[15];
    // char name;
    cout << "enter your name" << endl;
    cin >> ch;
    cout << endl<<"Name is : " << ch<<endl;

    cout << " Length is : " <<getlength(ch)<<endl;
    // cout << endl;

    // reverse(ch);
    // cout << ch;
    cout << "Palindrom is or not = "<<palindrom(ch);

    return 0;
}