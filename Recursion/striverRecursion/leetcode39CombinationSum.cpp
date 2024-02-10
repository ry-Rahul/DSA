#include <bits/stdc++.h>
using namespace std;
void printArr(vector<vector<int>> arr);

void solve(vector<int> arr,int target, vector<int> ds, vector<vector<int>> &ans,int ind){

    if(ind==arr.size()){
        if(target==0){
                ans.push_back(ds);
        }
        return;
    }

    if(target>=arr[ind]){
        ds.push_back(arr[ind]);
        solve(arr, target - arr[ind], ds, ans, ind);
        ds.pop_back();
    }
    solve(arr, target, ds, ans, ind+1);

}



void CombinationSum(vector<int> arr, int target){

    vector<int> ds;
    vector<vector<int>> ans;
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(target+1, -1));
    solve(arr, target, ds, ans,0);

// print the arrays
    printArr(ans);
}

//print 2D array
void printArr(vector<vector<int>> arr){
    for(auto it:arr){
        for(auto ele:it){
            cout << ele << " ";
        }
        cout << endl;
    }
}
int main()
{

    //   Input: candidates = [2,3,6,7], target = 7
    // Output: [[2,2,3],[7]]

    vector<int> v = {2, 3, 6, 7};
    int target = 7;

    CombinationSum(v, target);

    return 0;
}
