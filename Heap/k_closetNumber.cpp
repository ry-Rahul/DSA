#include <bits/stdc++.h>
using namespace std;
#include <cstdlib>

int main()
{
    priority_queue<pair<int, int>> pq;
    int arr[] = {5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "size of array is -> " << n << endl;
    int k = 3;
    int x = 7;
    for (int i = 0; i < 6; i++)
    {
        pq.push({abs(arr[i] - x) , arr[i]});
        if(pq.size()>k){
            pq.pop();
        }
    }

    while(pq.size()>0){
        cout << pq.top().second << " ";
        pq.pop();
    }
    


    return 0;
}