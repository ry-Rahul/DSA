#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target,int low, int high)
{
    if(low>high)return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, target,low, mid - 1);
    else
        return binarySearch(arr, target,mid+1, high);
}

int main()
{

    return 0;
}