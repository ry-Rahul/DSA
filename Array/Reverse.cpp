#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<int> reversee(vector<int> v)
{
    int l = 0, u = v.size()-1;
    while(l<=u)
    {
        swap(v[l], v[u]);
        l++;
        u--;
    }
       return v;
}
void printvec(vector<int> v)
{
    for(auto imp:v)
        cout << imp << " ";
    cout << endl;
}
int main()
{
    vector<int> v;
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    v.push_back(100);

    vector<int> ans = reversee(v);
    printvec(v);
    printvec(ans);

    return 0;
}