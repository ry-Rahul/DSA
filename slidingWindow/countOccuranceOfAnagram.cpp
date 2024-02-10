#include <bits/stdc++.h>
using namespace std;


bool allZero(vector<int> &hash){

    for(int i=0;i<26;i++){
        if(hash[i]!=0){
            return false;
        }
    }

    return true;
}
int search(string txt , string pat){

    int n=txt.size();
    vector<int> hash(26,0);

    // count the frequency of each character in pat
    for(char ch:pat){
        hash[ch-'a']++;
    }

    // sliding window
    int i=0 , j=0;
    int result=0;
    int k=pat.size();

    while(j<n){

        hash[txt[j]-'a']--;
        if(j-i+1==k){
            if(allZero(hash)){
                result++;
            }
            hash[txt[i]-'a']++;
            i++;
        }

        j++;
    }

    return result;
}
int main(){
  
   string s="xxorfxdofrhjfro";
    string p="for";

    cout<<search(s,p)<<endl;



  return 0;
}