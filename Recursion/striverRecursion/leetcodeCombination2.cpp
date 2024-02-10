#include <bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>> arr)
{
    cout << endl;
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
    cout << endl;
}


/* picking the element and not picking the element
    if we pick the first element then we can not pick the same second element move to next index and find that element is different or not if it is same then we can not pick that element
 */
void solve2(vector<int> arr, int target, vector<vector<int>> &ans, vector<int> ds, int ind)
{

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        // if the current element is greater than the target then we can not pick that element
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        solve2(arr, target-arr[i], ans, ds, i + 1);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    int ind = 0;
    solve2(candidates, target, ans, ds, ind);
    printArr(ans);

    return ans;
}

int main()
{
    //   Input: candidates = [10,1,2,7,6,1,5], target = 8
    // Output:
    // [
    // [1,1,6],
    // [1,2,5],
    // [1,7],
    // [2,6]
    // ]

    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // findCombination(v, target);
    combinationSum2(v, target);

    return 0;
}