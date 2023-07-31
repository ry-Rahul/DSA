#include <bits/stdc++.h>
using namespace std;

int k;
int noOfways(int level)
{
    if (level == k)
        return 1;
    if(level>k)
        return 0;

    return noOfways(level + 1) + noOfways(level + 2);
}

int main()
{
    int n,k;
    cout << "give total no of stairs of level and step >>" << endl;
    cin >> n>>k;
    cout << "NO of ways >> " << noOfways(n);
    return 0;
}