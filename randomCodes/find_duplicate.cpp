#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)



int main()
{
  int arr[]={4,5,6,7,2,3,9,1,8,8};
  int ans=0,i,j;

  for(int i=0; i<10; i++)
    ans=ans^arr[i];

  for (int j = 1 ; j <10 ; j++)
  {
     ans=ans^j;
  }
  
  cout<<ans;
  

  return 0;
}