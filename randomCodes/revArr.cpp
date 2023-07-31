#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void reverse(int a[],int n)
{
    int start=0;
    int end =n-1;
     
     while(start<=end)
     {
        swap(a[start], a[end]);
        start++;
        end--;
     }
}



void revarr( int a[],int l)
{
    
    for (int i = 0; i < l/2; i++)
    {
        swap(a[i],a[l-i-1]);
    }
    
}
void showarr(int n[],int l)
{
    for (int j = 0; j < l; j++)
    {
        cout<<n[j]<<" ";
    }
}
int main()
{
    int j;
  int c[]={1,2,3,4,5,6};
  
   revarr(c,6);
   showarr(c,6);
  return 0;
}