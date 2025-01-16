#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        // pop all the elements from the stack which are smaller than the current element
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}

void nextGreaterEle(vector<int>& nums){
    int n= nums.size();
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[i]=-1;
        for(int j=i+1; j<n; j++){
            if(nums[j]>nums[i]){,
                ans[i]=nums[j];
                break;
            }
        }
    }
}

// variation of this problem is to find the next greater element in circular array
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    stack<int> st;
    unordered_map<int, int> mp;

    vector<int> ans(n);

    for (int i = 0; i < m; i++)
    {

        while (st.size() > 0 && st.top() < nums2[i])
        {
            mp[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    while (st.size() > 0)
    {
        mp[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = mp[nums1[i]];
    }

    return ans;
}

int main()
{

    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> ans = nextGreaterElement(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans1 = nextGreaterElement(nums1, nums2);
    for (auto it : ans1)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}