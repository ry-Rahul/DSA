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


// print subsequence using recursion 
void helperSolve(int arr[], int n, int ind, vector<int> &ds)
{

    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // pick the element
    ds.push_back(arr[ind]);
    helperSolve(arr, n, ind + 1, ds);

    // do not pick the element
    ds.pop_back();
    helperSolve(arr, n, ind + 1, ds);
}
void printSubSeqRec(int arr[], int n)
{
    vector<int> ds;
    helperSolve(arr, n, 0, ds);
}

// print only one subsequnce which is equal to k
bool OnlyOneSolToK(int arr[], int n, int ind, int k, int sum, vector<int> ans)
{

    if (n == ind)
    {
        if (sum == k)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
            return false;
    }

    ans.push_back(arr[ind]);
    sum += arr[ind];
    if (OnlyOneSolToK(arr, n, ind + 1, k, sum, ans) == true)
    {
        return true;
    }
    ans.pop_back();
    sum -= arr[ind];
    if (OnlyOneSolToK(arr, n, ind + 1, k, sum, ans) == true)
    {
        return true;
    };

    return false;
}

// solve function
void solve(int arr[], int n, int ind, int k, int sum, vector<int> ans)
{

    if (n == ind)
    {
        if (sum == k)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    ans.push_back(arr[ind]);
    sum += arr[ind];
    solve(arr, n, ind + 1, k, sum, ans);
    ans.pop_back();
    sum -= arr[ind];
    solve(arr, n, ind + 1, k, sum, ans);
}
// sum is equal to k in subsequence
void printSumIsK(int arr[], int n, int k)
{
    vector<int> ds;

    solve(arr, n, 0, k, 0, ds);
}

// count the sum of subsequence is equal to k
int countSubSeqIsK(int arr[], int n, int ind, int k, vector<int> ans, int sum)
{

    if (ind == n){
        if (sum == k)
        {
            return 1;
        }
        else
            return 0;
    }

    sum += arr[ind];
    int left = countSubSeqIsK(arr, n, ind + 1, k, ans, sum);

    sum -= arr[ind];
    int right = countSubSeqIsK(arr, n, ind + 1, k, ans, sum);
    return left + right;
}

int main()
{

    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // printSubSequence(arr, n);
    // printSubSeqRec(arr, n);
    // printSumIsK(arr, n, 4);

    vector<int> ans;
    // OnlyOneSolToK(arr, n, 0, 2, 0, ans);

    // count number of subSequence is equal to k
    cout << countSubSeqIsK(arr, n, 0, 3, ans, 0) << endl;

    return 0;
}