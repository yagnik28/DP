#include<bits/stdc++.h>
using namespace std;
#define int long long

// T.C => O(m*n)
// S.C => O(m*n)

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
    
    // base case
    dp[0][0] = 1; 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0)
            {
                dp[0][0] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if(i > 0)
                {
                    up = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    cout << dp[m-1][n-1] << endl;

    return 0;
}