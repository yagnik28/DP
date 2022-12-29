#include<bits/stdc++.h>
using namespace std;

// Memoization 

// T.C ==> O(3*4*N)
// S.C ==> O(N) + O(3*N)

// 3-TASKS ==> 0 -> Task_1 done before, 1 -> Task_2 done before, 2 -> Task_3 done before, 3 -> Not any Task done before.

int max_points(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &a)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int task=0;task<3;task++)
        {
            if(task != last)
            {
                maxi = max(maxi, a[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != (-1))
    {
        return dp[day][last];
    }
    int maxi = 0;
    for(int task=0;task<3;task++)
    {
        if(task != last)
        {
            int point = a[day][task] + max_points(day - 1, task, dp, a);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (3));
    vector<vector<int>> dp(n, vector<int> (4, -1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << max_points(n-1, 3, dp, a) << endl;

    return 0;
}