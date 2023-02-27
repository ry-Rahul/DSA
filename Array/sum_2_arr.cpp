#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void printArr(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    // cout << endl;
}
void reverse(vector<int> v)
{
    int n = 0;
    int m = v.size() - 1;

    while (n <= m)
    {
        swap(v[n++], v[m--]);
    }
}
vector<int> findArrSum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;

    vector<int> ans;

    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    // first case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // second case
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    // third case

    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    reverse(ans);
    return ans;
}

int main()
{
    vector<int> v1 = {3, 3};
    vector<int> v2 = {4, 5, 1};
    printArr(v1);
    cout << " + ";
    printArr(v2);
    cout << " = ";
    vector<int> result = findArrSum(v1, 2, v2, 3);
    printArr(result);

    return 0;
}