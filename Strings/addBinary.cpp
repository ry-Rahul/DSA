#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        
        int n=a.size();
        int k=b.size();

        int i=n-1; 
        int j=k-1;
        string ans="";
        int carry=0;

        while(i>=0 || j>=0){
            int c= (i>=0)? a[i]-'0':0;
            int d= (j>=0)? b[j]-'0' :0;

            int sum=c+d +carry;

            ans=to_string(sum%2)+ans;

            carry=sum/2;

            i--;
            j--;
            
        }

        if(carry){
            ans='1'+ans;
        }

        return ans;
    }
};
int main(){

    string a = "11";
    string b = "1";

    Solution s;
    cout<<s.addBinary(a,b)<<endl;

    

    return 0;
}