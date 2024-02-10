#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        int n=popped.size();

        for(int i=0;i<pushed.size();i++){

            st.push(pushed[i]);

            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            
        }

        return st.empty();
    }
};
int main(){

    Solution s;
    vector<int> pushed={1,2,3,4,5};
    vector<int> popped={4,5,3,2,1};
    cout<<s.validateStackSequences(pushed,popped)<<endl;
  

  return 0;
}