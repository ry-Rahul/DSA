#include <bits/stdc++.h>
using namespace std;

bool recursiveSort(int *arr,int size)
{
    if(size==0 || size==1)
      return true;
    else if(arr[0]>arr[1])
      return false;
    else
      recursiveSort(arr+1,size-1);
}

int main()
{
  int arr[] = {4, 5, 6, 8, 9, 2, 16, 20, 25, 30};
  bool ans = recursiveSort(arr, 10);

  if(ans)
    cout << "Array is sorted" << endl;
  else
    cout << "Array is not sorted" << endl;

  return 0;
}