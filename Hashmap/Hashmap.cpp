#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)



int main()
{
    int arr[]={1,2,2,3,1,4,4,5,6},count=0;
    char ch;

    for (int i = 0; i < 9; i++){
        int temp = arr[i];
        count = 0;
        for (int j = 1; j < 9; j++)
        {
            if(temp==arr[j]){
                count++;
            }
        }
        cout<<temp<<" "<<count<<endl;
    }

        return 0;
}