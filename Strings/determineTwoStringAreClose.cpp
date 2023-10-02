#include <bits/stdc++.h>
using namespace std;

// leetcode-1657
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i = 0 ; i<n; i++){
            
            int ind = word1[i]-'a';
            freq1[ind]++;
        }
        for(int i = 0 ; i<m; i++){
            
            int ind = word2[i]-'a';
            freq2[ind]++;
        }

        /*
        
        // print the freq1 array
        for(int i = 0 ; i<26; i++){
            cout<<freq1[i]<<" ";
        }
        cout<<endl;
        // print the freq2 array
        for(int i = 0 ; i<26; i++){
            cout<<freq2[i]<<" ";
        }

        */
       
        // check if the freq1 and freq2 are equal
        for(int i = 0 ; i<26; i++){
            if(freq1[i] !=0 && freq2[i] ==0  || freq1[i] ==0 && freq2[i] !=0){
                return false;
            }
        }

        // check if the freq1 and freq2 are equal
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());

        for(int i = 0 ; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }

        return true;
    }
};
int main(){

    Solution s;
    cout<<s.closeStrings("abc","bca")<<endl;
    cout<<s.closeStrings("a","aa")<<endl;
    cout<<s.closeStrings("cabbba","abbccc")<<endl;
    cout<<s.closeStrings("cabbba","aabbss")<<endl;
  

  return 0;
}