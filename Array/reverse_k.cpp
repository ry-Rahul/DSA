#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void printvec(vector<int> v)
{
    for (auto imp : v)
        cout << imp << " ";
    cout << endl;
}
vector<int> reversee(vector<int> &v, int k)
{
    int l = k, u = v.size() - 1;
    // for (int i = 0; i < (v.size() - k) / 2 ; i++)
    // {
    //     cout << v[l] << " " << v[u] << endl;
    //     swap(v[l++], v[u--]);
    // }
    while(k<=u)
    {
        cout << v[k] << " " << v[u] << endl;
        swap(v[k++], v[u--]);
    }
    return v;
}
int main()
{
    // 1 2 3 4 5 6
    // 6 2 3 4 5 1
    // .
    // .
    // .
    // 1 2 3 4 5 6
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // v.push_back(12);
    // v.push_back(13);
    // v.push_back(14);
    // v.push_back(15);
    // v.push_back(16);
    // v.push_back(100);
    // int n;
    // cin >> n;
    printvec(v);
    vector<int> ans = reversee(v, 3);
    printvec(ans);

    return 0;
}