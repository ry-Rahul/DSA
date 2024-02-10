#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        queue<int> q;
        for(int i=1; i<=8; i++){
            q.push(i);
        }

        vector<int> res;
        while(!q.empty()){

            int temp=q.front();

            if(temp>=low && temp<=high){
                res.push_back(temp);
            }
            q.pop();

            int last_digit=temp%10;
            if(1+last_digit<=9){
                temp=temp*10 + 1+last_digit;
                q.push(temp);
            }
        }

        return res;
    }
};
int main(){
  

  return 0;
}