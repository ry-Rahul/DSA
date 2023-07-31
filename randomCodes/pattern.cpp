#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)



int main()
{
  int i=1,j=1,n;
  n=4;
  while (i<=n)
  {
      j=1;
      while (j<=n)
      {
        cout<<j<<" ";
        j +=1;;
      }
      cout<<endl;
      i +=1;
  }
  

  return 0;
};
