#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 1;

int min_sum_grid(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
    {
        return a[0][0];
    }
    if(i < 0 || j < 0)
    {
        return INF;
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }
    int up = a[i][j] + min_sum_grid(i-1, j, a, dp);
    int left = a[i][j] + min_sum_grid(i, j-1, a, dp);
    return dp[i][j] = min(up, left);
}

int32_t main()
{
    int m, n;
    cin >> m >> n; // m -> rows, n -> colums 
    // m = 1, n = 5 => [1, 2, 3, 4, 5]

    /* m = 2, n = 5 => [1, 2, 3, 4, 5]
                       [6, 7, 8, 9, 10]
    */
    vector<vector<int>> a(m, vector<int> (n ,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
    cout << min_sum_grid(m-1, n-1, a, dp);

    return 0;
}

/*
    TESTCASE : 
        3 3
        5 4 9
        10 3 6
        1 7 2
    ANS : 
        20

    TESTCASE : 
        2 3
        5 9 6 
        11 5 2
    ANS : 
        21
*/