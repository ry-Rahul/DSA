#include <bits/stdc++.h>
using namespace std;

void printRec(int n, string name)
{
    if (n == 0)
    {
        return;
    }
    cout << name << endl;
    printRec(n - 1, name);
}

void printNumbers(int n)
{
    if (n == 0)
    {
        return;
    }
    printNumbers(n - 1);
    cout << n << endl;
}

string solve(string str, int st, int end){
    
    if(st>=end){
        return str;
    }
    swap(str[st], str[end]);
    return solve(str, st+1, end-1);
}

bool isPalindrome(string str, int st, int end){
    if(st>=end){
        return true;
    }
    if(str[st]!=str[end]){
        return false;
    }
    return isPalindrome(str, st+1, end-1);
}

void printReverse(string str){

    cout<<solve(str, 0,str.size()-1)<<endl;

}

int main()
{

    int n = 5;
    string name = "Rahul";
    // printRec(n, name);
    // printNumbers(n);
    printReverse("Rahul");

    return 0;
}