#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    cout << "using priority Queue here " << endl;

    // max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(90);
    pq.push(50);
    pq.push(12);
    pq.push(10);

    pq.pop();

    cout << endl
         << "Top element is >> " << pq.top() << endl;
    cout << "size is >> " << pq.size() << endl;

    if (pq.empty()){
        cout << "Heap is empty " << endl;
    }
    else{
        cout << "Heap is not empty " << endl
             << endl;
    }

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(90);
    minheap.push(50);
    minheap.push(12);
    minheap.push(10);

    cout << endl
         << "Top element is >> " << minheap.top() << endl;
    cout << "size is >> " << minheap.size() << endl<<endl;
    



    return 0;
}