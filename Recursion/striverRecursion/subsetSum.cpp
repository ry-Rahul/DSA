#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int N, vector<int> &ds, int ind, int sum)
{

    if (ind == arr.size())
    {
        ds.push_back(sum);

        return;
    }

    sum += arr[ind];
    // ds.push_back(sum);
    solve(arr, N, ds, ind + 1, sum);

    sum -= arr[ind];
    // ds.pop_back();
    solve(arr, N, ds, ind + 1, sum);
}
void subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ds;

    solve(arr, N, ds, 0, 0);
    for(auto it :ds)
        cout << it << " ";
    cout << endl;
}
int main()
{

    vector<int> arr = {2,3};
    //sum of all subsets of arr  0 2 3 5
    int N = 2;
    subsetSums(arr, N);

    return 0;
}