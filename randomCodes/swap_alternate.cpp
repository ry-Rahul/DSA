#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void swap_alter(int a[],int n)
{
    int start=0;
    int end =n-1;
     
     while(start<=end)
     {
        swap(a[start], a[start+1]);
        start +=2;;
        //end--;
     }
    //  for (int i = 0; i <n; i +=2)
    //  {
    //     if(i+1<n)
    //     swap(a[i],a[i+1]);
    //  }
     
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
  int a[]={1,2,3,4,5,6};
  swap_alter(a,6);
  showarr(a,6);

  return 0;
}