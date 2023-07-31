#include <bits/stdc++.h>
using namespace std;

long long power(int x, int y)
{
    if (y == 0)
        return 1;

    if (y == 1)
        return x;

    // Recursive call
    long long ans = power(x, y / 2);

    // if y is even
    if (y % 2 == 0)
        return ans * ans;
    else // if y is odd
        return x * ans * ans;
}

int main()
{
    int x = 2, n , t,k, result = 0, y = 0;
    cout << "Enter Binary number for its decimal:" << endl;
    cin >> n;
    k = n;

    while (n)
    {
        t = n % 10;
        if (t == 1)
        {
            result = result + power(x, y);
        }
        y++;
        n = n / 10;
    }
    cout <<"Decimal of "<<k<<" -> "<< result;

    return 0;
}