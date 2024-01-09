#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long maxSum = 0, sum = 0, prev = 0;
    int i = 0,j=0;
    while(i<k){
        sum += a[i++];
    }
    maxSum = sum;

    while(i<n){
        sum += a[i++];
        prev+=a[j++];
        maxSum = max(maxSum,sum);

        if(prev<0){
            sum -= prev;
            prev = 0;
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}
int main()
{
    long long  arr[] = {1, -2, 2, -3};
    long long n = sizeof(arr) / sizeof(arr[0]);
    long long k = 2;
    cout << maxSumWithK(arr, n, k) << endl;

    return 0;
}