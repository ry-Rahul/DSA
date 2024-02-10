#include <bits/stdc++.h>
using namespace std;
int nextGreaterElement(int n)
{
    vector<int> nums;
    int k = n;
    while (k > 0)
    {
        int rem = k % 10;
        nums.push_back(rem);
        k = k / 10;
    }
    reverse(nums.begin(), nums.end());

    // for (int i : nums)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    int ind = -1;
    int s = nums.size();

    for (int i = s - 2; i >= 0; i--)
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }

    if (ind == -1)
    {
        return -1;
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    int ans = 0;
    for (int i : nums)
    {
        ans = ans * 10 + i;
    }

    cout << "Int Max " << INT_MAX << endl;

    if (ans > INT_MAX)
    {
        return -1;
    }
    
}
int main()
{

    //   Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
    //
    int n = 2147483486;
    cout << nextGreaterElement(n) << endl;

    return 0;
}