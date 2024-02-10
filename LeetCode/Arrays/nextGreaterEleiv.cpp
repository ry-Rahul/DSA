#include <bits/stdc++.h>
using namespace std;

vector<int> secondGreaterElement(vector<int> &nums)
{
    stack<int> s;
    vector<int> ans(nums.size(), -1);

    
}
int main()
{

    // Input: nums = [2,4,0,9,6]
    // Output: [9,6,6,-1,-1]

    vector<int> nums = {2, 4, 0, 9, 6};

    vector<int> ans = secondGreaterElement(nums);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}