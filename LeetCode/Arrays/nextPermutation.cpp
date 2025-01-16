#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();

    // find the first decreasing element from the end
    // 2, 1, 5, 4, 3, 0, 0
    for (int i = n - 2; i >= 0; i--)
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i=n-1;i>=0;i--){
        if(nums[i]>nums[ind]){
            swap(nums[i],nums[ind]);
            break;
        }
    }

    reverse(nums.begin()+ind+1,nums.end());



    //  3 4 2 5
    //  3 4 5 2
}

int main()
{

    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(nums);
    for (auto it : nums)
        cout << it << " ";
    cout << endl;

    return 0;
}