#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &nums){
    int prev = nums[0];
    int prev2 = 0;
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;
        int notTake = prev;

        int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}


int rob(vector<int> &nums)
{
    vector<int> temp1, temp2;
    int n = nums.size();
    if(n==1)  return nums[0];
    for (int i = 0; i < n; i++){
        if (i != 0) 
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    
    }

    int ans1 = solve(temp1);
    int ans2 = solve(temp2);

    return max(ans1, ans2);
}


int main()
{
//     Input: nums = [1,2,3,1]
// Output: 4

    vector<int> nums = {1, 2, 3, 1};
    int ans = rob(nums);
    cout<<ans<<endl;
    return 0;
}
