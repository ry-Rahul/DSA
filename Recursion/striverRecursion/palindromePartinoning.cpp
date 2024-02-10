#include <bits/stdc++.h>
using namespace std;

// leetCode 131. Palindrome Partitioning
bool isPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;

}

void solve(int index,string s,vector<string> &path,vector<vector<string>> &ans){
    if(index==s.size()){
        ans.push_back(path);
        return;        
    }
    for (int i = index; i < s.size(); i++){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            solve(i+1,s,path,ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> path;
    solve(0,s,path,ans);
    return ans;
}

int main(){

    string s = "aaa";
    vector<vector<string>> ans = partition(s);
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
  

  return 0;
}