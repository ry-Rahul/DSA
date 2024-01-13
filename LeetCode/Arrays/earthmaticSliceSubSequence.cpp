#include <bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>> arr){
    for(auto it : arr){
        for(auto it2 : it){
            cout << it2 << " ";
        }
        cout << endl;
    }

}
void solve(vector<vector<int>> &ans, vector<int> &ds, vector<int> nums, int ind)
{

    if (ind == nums.size())
    {
        if (ds.size() >= 3)
            ans.push_back(ds);
        return;
    }

    if (ds.size() >= 2)
    {
        if (ds[ds.size() - 1] - ds[ds.size() - 2] != nums[ind] - ds[ds.size() - 1])
            return;
    }
    ds.push_back(nums[ind]);
    solve(ans, ds, nums, ind + 1);
    ds.pop_back();
    solve(ans, ds, nums, ind + 1);
}

int numberOfArithmeticSlices(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;

    solve(ans, ds, nums, 0);
    printArr(ans);
    return 0;
}


int main()
{
    vector<int> arr = {2, 4, 6, 8, 10};
    cout<<numberOfArithmeticSlices(arr)<<endl;

    return 0;
}