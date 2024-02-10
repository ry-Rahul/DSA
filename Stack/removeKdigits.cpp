#include <bits/stdc++.h>
using namespace std;

string removeKDigits(string num , int k){

    int n=num.size();
    stack<char> st;

    for(char ch:num){

        while(!st.empty() && k>0 && st.top()>ch){
            st.pop();
            k--;
        }

        if(!st.empty() || ch!='0'){
            st.push(ch);
        }
    }

    // if k is not zero
    while(!st.empty() && k--){
        st.pop();
    }

    if(st.empty()){
        return "0";
    }

    while(!st.empty()){
        num[n-1]=st.top();
        st.pop();
        n--;
    }

    return num.substr(n);
}
int main(){

    string num="1432219";
    int k=3;

    cout<<removeKDigits(num,k)<<endl;
  

  return 0;
}