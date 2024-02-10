#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                       int k)
    {
        priority_queue<p, vector<p>> pq;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums1[i] + nums2[j];

                if (pq.size() < k)
                {
                    pq.push({sum, {i, j}});
                }
                else if (pq.top().first > sum)
                {
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
                else
                {
                    break;
                }
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i], nums2[j]});
        }

        return ans;
    }
};
int main()
{

    /* Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6] */

    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution obj;
    vector<vector<int>> ans = obj.kSmallestPairs(nums1, nums2, k);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}