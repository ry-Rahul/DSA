#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void showarr(int n[],int l)
{
    for (int j = 0; j < l; j++)
    {
        cout<<n[j]<<" ";
    }
}
void find_unique(int a[],int size)
{

    int ans=0;
    for(int i=0; i<size; i++)
    ans=ans^a[i];

    for(int j=1; j<size; j++)
    ans=ans^j; // a^a = 0, a^0 = a (XOR property



    cout<<ans;
}
int main()
{
   int arr[]={1,3,4,2,2};
   int n= sizeof(arr)/sizeof(arr[0]);
   find_unique(arr,n);
      

  return 0;
}