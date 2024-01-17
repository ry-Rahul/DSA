#include <bits/stdc++.h>
using namespace std;
// leetcode 3008
class Solution {
public:
    void computeLPS(string str, vector<int>& LSP) {
        int M = str.length();
        int i = 1;
        LSP[0] = 0;
        int len = 0;

        while (i < M) {
            if (str[i] == str[len]) {
                len++;
                LSP[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LSP[len - 1];
                } else {
                    LSP[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pat, string txt) {
        int M = pat.length();
        int N = txt.length();

        vector<int> result;
        vector<int> LSP(M, 0);

        computeLPS(pat, LSP);

        int i = 0, j = 0;

        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == M) {
                result.push_back(i - M);
                j = LSP[j - 1];
            } else if (txt[i] != pat[j]) {
                if (j != 0) {
                    j = LSP[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> index_i = search(a, s);
        vector<int> index_j = search(b, s);
        int n = s.size();

        vector<int> res;
        for (int &i : index_i) {
            int left_limit = max(0, i - k);
            int right_limit = min(n - 1, i + k);

            auto it = lower_bound(begin(index_j), end(index_j), left_limit);
            if (it != index_j.end() && *it <= right_limit) {
                res.push_back(i);
            }
        }

        return res;
    }
};
int main(){

    // Input: s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15
// Output: [16,33]

    string s = "isawsquirrelnearmysquirrelhouseohmy";
    string a = "my";
    string b = "squirrel";
    int k = 15;
    Solution obj;
    vector<int> ans = obj.beautifulIndices(s,a,b,k);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

  return 0;
}