#include <bits/stdc++.h>
using namespace std;
 string minWindow(string s, string t) {
        
        int n=s.size();
        int m=t.size();

        if(n<m){
            return "";
        }

        unordered_map<char,int> mp;
        for(char ch:t){
            mp[ch]++;
        }

        int start_idx = 0;
        int i=0;
        int j=0;
        int window_size=INT_MAX;
        int required_cnt=t.size();

        while(j<n){
            char ch= s[j];

            // it means we need this character
            if(mp[ch]>0){
                required_cnt--;
            }

            mp[ch]--;

            // start contracting the window
            while(required_cnt==0){
                int curr_window_size = j-i+1;
                if(curr_window_size<window_size){
                    window_size=curr_window_size;
                    start_idx=i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0){
                    required_cnt++;
                }

                i++;
            }

            j++;
        }

        if(window_size==INT_MAX){
            return "";
        }

        return s.substr(start_idx,window_size);
 }
int main(){

    string s="ADOBECODEBANC";
    string t="ABC";

    cout<<minWindow(s,t)<<endl;
  

  return 0;
}