#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegative(vector<int> &v,int k){
    int n=v.size();
    int i = 0;
    int j = 0;

    vector<int> ans;
    queue<int> q;

    while(j<n){

        if(v[j]<0){
            q.push(v[j]);
        }

        if(j-i+1==k){
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.front());
                if(v[i]==q.front()){
                    q.pop();
                }
            }
            i++;
        }
        j++;
    }

    return ans;
}
int main(){

    vector<int> v={12, -1, -7, 8, -15, 30, 16, 28};
    int k=3;
    vector<int> ans=firstNegative(v,k);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
  

  return 0;
}