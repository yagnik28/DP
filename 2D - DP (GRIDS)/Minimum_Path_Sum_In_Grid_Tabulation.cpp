#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 1;

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
    
    // base case
    dp[0][0] = a[0][0];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = a[i][j];
            }
            else
            {
                int up;
                if(i > 0)
                {
                    up = a[i][j] + dp[i-1][j];
                }
                else if(i < 0)
                {
                    up = a[i][j] + INF; 
                }

                int  left;
                if(j > 0)
                {
                    left = a[i][j] + dp[i][j-1];
                }
                else if(j < 0)
                {
                    up = a[i][j] + INF;
                }

                dp[i][j] = min(up, left);
            }
        }
    }
    cout << dp[m-1][n-1] << endl;

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