#include <bits/stdc++.h>
using namespace std;

int min_sprinklers(int arr[], int n)
{
    // code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] != -1)
            v.push_back({max(0, i - arr[i]), min(n - 1, i + arr[i])});
    }

    sort(v.begin(), v.end());

    int ans = 0;

    int target = 0;

    int maxIndex = 0;
    int i = 0;

    while (target < n)
    {

        maxIndex = -1;

        while (i < v.size() && v[i].first <= target)
        {
            maxIndex = max(maxIndex, v[i].second);
            i++;
        }

        if (maxIndex < target)
        {
            return -1;
        }
        ans++;
        target = maxIndex + 1;

          if(target>=n){
              break;
          }
    }

    return ans;
}
int main()
{

    int arr[] = {-1, 2, 2, -1, 0, 0};
    // 2 3 4 -1 0 0 0 0 0
    // int arr[] = {1, 0, 4, 0, 4, 1, 4, 3, 1, 1, 1, 2, 1, 4, 0, 3, 0, 3, 0, 3, 0, 5, 3, 0, 0, 1, 2, 1, 2, 4, 3, 0, 1, 0, 5, 2};
    // int n = 36;
    cout << min_sprinklers( arr,6);

    return 0;
}