#include <bits/stdc++.h>
using namespace std;

void sayDigit(int n,string arr[])
{
       if(n==0)
           return;
        
        // Proccesing
       int digit = n % 10;
    //    n = n / 10;

    //    recursive
       sayDigit(n/10, arr);
       cout << arr[digit]<<" ";

}


int main()
{
    string str[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "six", "Seven", "Eight", "Nine"};
    cout << "Enter Any number" << endl;
    int n;
    cin >> n;

    sayDigit(n, str);
    // 

    return 0;
}