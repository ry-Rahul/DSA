#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4, 3, 5, 6};
    int n = 4;
    int a, b, sum = 0, cost = 0;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++) minheap.push(arr[i]);


    while (minheap.size() > 1)
    {
        a = minheap.top();
        minheap.pop();
        b = minheap.top();  
        minheap.pop();
        sum = sum + a + b;
        minheap.push(a + b);
    }

    cout << endl
         << "minimum cost is " << sum<<endl;

    return 0;
}