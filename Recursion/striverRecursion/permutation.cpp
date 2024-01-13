#include <bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>> arr)
{
    for (auto it : arr)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "]";
        cout << endl;
    }
}
// ________________PERMUTATION_WITHOUT_EXTRA_SPACE____________________
void withoutExtraSpace(vector<int> nums, vector<vector<int>> &ans, int ind)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[i], nums[ind]);
        withoutExtraSpace(nums, ans, ind + 1);
        swap(nums[i], nums[ind]);
    }
}


// ________________PERMUTATION_WITH_EXTRA_SPACE____________________
void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> ds, int freq[])
{
    //Permutation is a subset of Combination
    if (ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++){
        if (!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            solve(nums, ans, ds, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    } 
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    memset(freq, 0, sizeof(freq));
    solve(nums, ans, ds, freq);
    printArr(ans);
    return ans;
}
int main()
{

    vector<int> arr = {1, 1,2};
    permute(arr);

    cout<<"__________________________"<<endl;
    vector<vector<int>> ans;
    withoutExtraSpace(arr, ans, 0);
    printArr(ans);


    return 0;
}