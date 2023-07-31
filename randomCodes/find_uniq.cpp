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
    int find=0;
    for (int i = 0; i <size; i++)
    {
        find= find^a[i];
    }
    cout<<find;
}
int main()
{
   int arr[]={4,6,8,9,11,6,4,9,8};
   find_unique(arr,9);
      

  return 0;
}