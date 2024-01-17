#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)


void printarr(int arr[][2]){

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    //max heap 
    priority_queue<pair<int,pair<int,int>>> pq;
    int k = 2;

    int arr[4][2] = {{1,3},{-2,2},{5,8},{0,1}};

    // printarr(arr);

    for (int i = 0; i < 4;i++){
        // arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1] = x^2 + y^2 
        pq.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});
        if(pq.size()>k)
            pq.pop();
    }

        while (pq.size() > 0)
        {
            pair<int, int> p = pq.top().second;
            cout << p.first << " " << p.second << endl;
    
            pq.pop();
        }
    
    return 0;
}