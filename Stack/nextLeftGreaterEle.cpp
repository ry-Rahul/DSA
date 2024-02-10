#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        // pop all the elements from the stack which are smaller than the current element
        while (!st.empty() && st.top() >= nums[i])
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


vector<int> nextGreaterBruteForce(vector<int> &nums){
    vector<int> ans(nums.size());
    for(int i=0;i<nums.size();i++){
      
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                ans[i]=nums[j];
                break;
            }
        }
    }
    return ans;

}
int main()
{

    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = nextGreaterElement(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    vector<int> ans2 = nextGreaterBruteForce(arr);

    for (auto it : ans2)
    {
        cout << it << " ";
    }

    return 0;
}