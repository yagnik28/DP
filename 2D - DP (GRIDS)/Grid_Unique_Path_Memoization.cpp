#include<bits/stdc++.h>
using namespace std;
#define int long long

// T.C => O(m*n)
// S.C => O(m+n-2) + O(m*n)

int unique_path(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
    {
        return 1;
    }
    if(i < 0 || j < 0)
    {
        return 0;
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }
    int up = unique_path(i-1, j, a, dp);
    int left = unique_path(i, j-1, a, dp);
    return dp[i][j] = up + left;
}

int32_t main()
{
    int m, n;
    cin >> m >> n; // m -> rows, n -> colums 

    vector<vector<int>> a(m, vector<int> (n ,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
    cout << unique_path(m-1, n-1, a, dp);

    return 0;
}