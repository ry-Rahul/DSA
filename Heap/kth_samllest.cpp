#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
// find the 3rd smallest element from array 7 10 4 3 20 15
int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int> pq;
    // cout << pq.size();
    for (int i = 0; i < 6; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    
    cout << endl;

    cout << k << "rd smallest number>> " << pq.top();

    return 0;
}