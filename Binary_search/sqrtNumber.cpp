#include <bits/stdc++.h>
using namespace std;

long long int mySqrt(int x) {
        long long ans;
        int s=0;
        int e=x;
        long long int mid;

        while(s<=e){
            mid = s + (e-s)/2;

            if(x==mid*mid){
                return mid;
            }
            else if(mid*mid>x){
                 e = mid-1;
            }
            else{
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
}

double morePrecision(int n, int precise, int tempSol){
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0;i<precise;i++){

        factor = factor/10;
        
        for(double j= ans ; j*j <= n ; j+=factor){
            ans = j;
        }
    }
    return ans; 
}

int main(){
  
  int n = 8;
  int tempSol = mySqrt(n);

  cout<<"Precise sqrt of "<<n<<" is "<<morePrecision(n,3,tempSol)<<endl;


  return 0;
}