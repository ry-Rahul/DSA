#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    


    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        int result=0;

        unordered_map<long,long> mp[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long long diff=(long)nums[i] - nums[j];

                auto it = mp[j].find(diff);

                int count_at_j = it == mp[j].end() ? 0: it->second; //count at j for difference = diff

                mp[i][diff]+=count_at_j +1;
                result +=count_at_j;
            }
        }
        return result;
    }
};

int main(){

    vector<int> arr = {2,4,6,8,10};
    Solution s;
    cout<<s.numberOfArithmeticSlices(arr)<<endl;
  

  return 0;
}