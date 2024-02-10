/* #include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int n)
{
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    // cout << endl;
    int rank = 1;
    for (auto &i : mp)
    {
        mp[i.first] = rank++;
    }
    // for (auto &i : mp)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[arr[i]]);
    }
    return ans;
}
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> heapRank(vector<int> arr)
{
    vector<int> ans(arr.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i], i});
    }

    int rank = 1;

    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int idx=temp.second;
        ans[idx]=rank++;
    }

    return ans;
}
int main()
{

    vector<int> arr = {4, 7, 2, 90};
    vector<int> ans2 = heapRank(arr);
    for (auto &i : ans2)
    {
        cout << i << " ";
    }

    return 0;
}