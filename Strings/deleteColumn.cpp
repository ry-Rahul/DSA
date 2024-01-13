#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;

        for(int i = 0 ; i<m; i++){
            for(int j = 1 ; j<n; j++){
                if(strs[j][i] < strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }

        // prinnt the array 
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m; j++){
                  cout<<strs[i][j]<<" ";
            }
            cout<<endl;
        }
        return count;
    }
};
int main(){
//   Input: strs = ["cba","daf","ghi"]
// Output: 1
// Explanation: The grid looks as follows:
//   cba
//   daf
//   ghi

     Solution s;
        // vector<string> strs = {"cba","daf","ghi"};
        // vector<string> strs = {"a","b"};
        vector<string> strs = {"rrjk","furt","guzm"};
        cout<<s.minDeletionSize(strs)<<endl;

  return 0;
}