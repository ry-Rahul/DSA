#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &nums){

    stack<int> st;
    int n = nums.size();
    vector<int> arr(n);

    vector<int> ans(n);
    for (int i = 2 * n; i>=0; i--){
            
          while(!st.empty() && st.top()<=nums[i%n]){
              st.pop();
          }
            if(st.empty()){
                ans[i%n]=-1;
            }
            else{
                ans[i%n]=st.top();
            }
            st.push(nums[i%n]);
    }

        return ans;
}
vector<int> nextGreaterElements(vector<int> &nums)
{

    vector<int> ans = nextGreater(nums);

    return ans;
}
int main()
{

    // Input: nums = [1,2,3,4,3]
    // Output: [2,3,4,-1,4]

    vector<int> nums = {1, 2, 1};
    vector<int> ans = nextGreaterElements(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}