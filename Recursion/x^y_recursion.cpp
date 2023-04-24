#include <bits/stdc++.h>
using namespace std;

long long power(int x, int y)
{
    if (y == 0) return 1;
    if (y == 1) return x;

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
    int x, y;
    cout << "Enter x and y for find x^y" << endl
         << "x -> ";
    cin >> x;
    cout << endl
         << "y -> ";
    cin >> y;
    long long result = power(x, y);
    cout << endl
         << x << " ^ " << y << " = " << result;

    return 0;
}