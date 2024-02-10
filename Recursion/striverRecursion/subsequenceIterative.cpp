#include <bits/stdc++.h>
using namespace std;
void printSubSequence(int arr[], int n)
{

    // i<(1<<n) is same as i<2^n
    int len = pow(2, n);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // check if jth bit is set in i
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){

    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printSubSequence(arr, n);
  

  return 0;
}