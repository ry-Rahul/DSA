#include <bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>> &points)
{

    if (day == 0)
    {
        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + solve(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

// dp method
int solve2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    if (day == 0)
    {
        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + solve2(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    // return solve(n - 1, 3, points);

    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve2(n - 1, 3,points, dp);
}

int main()
{
    // 10 40 70
    // 20 50 80
    // 30 60 90
    int n = 3;
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    cout << ninjaTraining(n, points) << endl;

    return 0;
}