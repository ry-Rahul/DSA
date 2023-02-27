#include <bits/stdc++.h>
using namespace std;
// frequency sort :- sorting according to frequency of numbers

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    priority_queue<pair<int, int>> maxheap;

    // My first local approach 😂
    // priority_queue<int, vector<int>, greater<int>> pq;
    // for (int i = 0; i < 7; i++)
    // {
    //     pq.push(arr[i]);
    // }
    // while(pq.size()>0){
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    unordered_map<int, int> mp;

    for (int i = 0; i < 7; i++)
    {
        mp[arr[i]]++;
    }

    // print map elements and frequency

    // for (auto i =mp.begin(); i!=mp.end(); i++)
    // {
    //     cout << i->first << " " << i->second<<endl;
    // }
    // cout << endl;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxheap.push({i->second, i->first});
    }

    while (maxheap.size() > 0)
    {
        int freq = maxheap.top().first;
        int no = maxheap.top().second;
        for (int i = 0; i < freq; i++)
        {
            cout << no << " ";
        }
        maxheap.pop();
    }
    cout << endl;
    return 0;
}