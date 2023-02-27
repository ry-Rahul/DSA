#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<int> twoSum(vector<int> &nums, int target)
{
    int sum = 0, i, j;
    vector<int> a(2);
    for (int i = 0; i <+ nums.size(); i++)
    {
        int t = nums[i];
        if (i != j)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (t + nums[j] == target)
                {
                    a[0] = j;
                    a[1] = i;
                    break;
                }
            }
        }
        // break;
    }
    return a;
}

int main()
{

    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);

    vector<int> res = twoSum(v, 9);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}