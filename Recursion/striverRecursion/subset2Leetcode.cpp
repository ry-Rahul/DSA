#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int N, vector<int> &ds, int ind)
{

    if (ind == arr.size())
    {
        for (auto it : ds)
            cout << it;
        cout << endl;
        return;
    }

    ds.push_back(arr[ind]);
    solve(arr, N, ds, ind + 1);

    ds.pop_back();
    solve(arr, N, ds, ind + 1);
}
void subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ds;

    solve(arr, N, ds, 0);
}
int main()
{

    vector<int> arr = {1, 2, 2};
    int N = 3;
    subsetSums(arr, N);

    return 0;
}
