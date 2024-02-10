#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> v(n);

    for (int i = n - 1; i >= 0; i--)
    {
          //               0  1  2  3  4  5  6  7  8
       // vector<int> v = {4, 2, 1, 5, 6, 3, 2, 4, 2};

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            v[i] = n;
        }
        else
        {
            v[i] = st.top();
        }

        st.push(i);
    }

    return v;
}

vector<int> prevSmaller(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            v[i] = -1;
        }
        else
        {
            v[i] = st.top();
        }

        st.push(i);
    }

    return v;
}

void printArr(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int> lg = prevSmaller(heights);
    printArr(lg);

    vector<int> ng = nextSmaller(heights);
    printArr(ng);

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = ng[i] - lg[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    
    cout << maxArea << endl;


    return maxArea  ;
}
int main()
{
    //               0  1  2  3  4  5  6  7  8
    vector<int> v = {4, 2, 1, 5, 6, 3, 2, 4, 2};

    largestRectangleArea(v);

    return 0;
}