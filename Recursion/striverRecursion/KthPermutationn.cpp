#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string str = "";
    k = k - 1;
    while (true)
    {
        str += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return str;
}
int main()
{
    int n = 3, k = 3;
    cout << getPermutation(n, k) << endl;
    

    return 0;
}