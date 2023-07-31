#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>&v,int temp)
{
    // cout << "insertfxn" << endl;
    if (v.size() == 0 ||v[v.size()-1]<=temp)
        {
            v.push_back(temp);
            return;
        }

        int val = v[v.size() - 1];
        v.pop_back();

        insert(v,temp);
        v.push_back(val);
}
void sortArr(vector<int> &v)
{
    if(v.size()==1)
        return;
        // v.push_back(temp);

    int val = v[v.size()-1];

    v.pop_back();

    sortArr(v);
    insert(v, val);
}

void printarr(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if(i!=v.size()-1)
            cout << "___";
    }
    cout << endl;
}
int main()
{
    vector<int> v={9,8,7,6,5,4,3,2,1,0};

    printarr(v);
    sortArr(v);
    printarr(v);

    return 0;
}