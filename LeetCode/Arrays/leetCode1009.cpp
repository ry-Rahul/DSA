#include <bits/stdc++.h>
using namespace std;

    int deciToBinary(int num){
        int ans = 0;
        int i=0;

        while(num!=0){
            int bit = num&1;
            ans = bit*(pow(10,i))+ans;
            num = num>>1;
            i++;

        }
        return ans;
    }

    int ansReturn(int binary){
        int n = binary;
        // cout<<n<<endl;
        int i=0,ans=0; 

        while(n!=0){
            int rem = n%10;
            ans = ans + rem*(pow(2,i));
            i++;
            n /=10;
        }

        return ans;
    }
    int bitwiseComplement(int n) {
        int ans = deciToBinary(n);

        return ansReturn(ans);
    }

int main(){


    // cout<<bitwiseComplement(5)<<endl;
    cout<<deciToBinary(5)<<endl;
    cout<<ansReturn(101)<<endl;
    return 0;
}