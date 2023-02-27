#include <bits/stdc++.h>
using namespace std;
// #include <cstdlib>

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int k = 2;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    unordered_map<int, int> mp;
    for (int i = 0; i < 7; i++)
    {
        mp[arr[i]]++;
    }
    cout << "No._|_ frequency" << endl;
    for (auto x : mp)
    {
        cout << x.first << "  _|_ " << x.second << endl;
    }
    cout << endl;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        pq.push({i->second, i->first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (pq.size() > 0)
    {
        cout << pq.top().second << " ";
        pq.pop();
    }

    return 0;
}