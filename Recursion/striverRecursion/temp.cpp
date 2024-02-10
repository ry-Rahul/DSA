#include <bits/stdc++.h>
using namespace std;
int consecutiveOnes(vector<int> &arr)
{
    // Write your code here.
     int cnt=0;
    int maxcnt=0;
    for(int i =0 ;i<arr.size(); i++){
        
        if(arr[i]==1){
            cnt++;
            if(cnt>maxcnt){
                maxcnt=cnt;
            }
        }else if(arr[i]==0){
            cnt=0;
        }
    }
    return maxcnt;
}
int main()
{

    vector<int> arr = {0, 1, 1, 0, 0, 1, 1, 1};
    cout << consecutiveOnes(arr) << endl;

    return 0;
}