#include <bits/stdc++.h>
using namespace std;

// YOu have been given a number of stairs initially you are at the 0th stairs  and you need to reach the Nth stair each time you can either climb one step or two step you are supposed to return the number of distict ways in which you can climb from the 0th steps to Nth step 
int countDistict(long long nstairs)
{
     if(nstairs<0)
         return 0;
     if(nstairs==0)
         return 1;

     return countDistict(nstairs - 1) + countDistict(nstairs - 2);
}
int main()
{
    int n;
    cout << "Input no of stairs:" << endl;
    cin >> n;
    cout << countDistict(n)<<endl;

    return 0;
}