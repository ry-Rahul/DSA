#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void merge(int A[],int l,int mid,int u)
{
    int L[mid-l+1],R[u-mid],i,j,k;
    for ( i = 0; i < mid-l+1 ; i++)
    {
        /* code */
    }
    
}
void merge_sort(int A[],int l, int u)
{
    int mid;
    if(l<u)
    {
        mid=(l+u)/2;
        merge_sort(A,l,mid);
        merge_sort(A,mid+1,u);
        merge(A,l,mid,u)
    }
}

int main()
{
  

  return 0;
}