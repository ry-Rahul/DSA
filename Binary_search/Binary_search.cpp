#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int size , int key)
{
    int start = 0, mid,end= size-1;
    mid = start + (end-start)/2;

    while (start<=end)
    {
        if(arr[mid]==key)
            return mid;

        else if(arr[mid]<key)
            start=mid+1;
        
        else if (arr[mid] > key)
            end = mid - 1;
    
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
  int arr[]={2,4,6,9,12,23,26,36,78,99};
  int ans = binarySearch(arr, 10, 45);
  if(ans)
      cout << "Element is found at index -> " << ans << endl;
  else
      cout << "Element is not present in this array" << endl;

  return 0;
}