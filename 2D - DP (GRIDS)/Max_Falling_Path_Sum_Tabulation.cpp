#include<bits/stdc++.h>
using namespace std;

/* Recusrsion : 
    T.C => O(3^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*M)
// S.C => O(N*M) -> DP Array.

const int MINIMUM = -1e8;

int main()
{
    int n, m; // n -> rows, m -> columns.
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int> (m, -1));
    // BASE CASE 
    for(int j=0;j<m;j++)
    {
        dp[0][j] = a[0][j];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int up = a[i][j] + dp[i-1][j];

            int left_diagonal, right_diagonal;

            if((j-1) >= 0)
            {
                left_diagonal = a[i][j] + dp[i-1][j-1];
            }
            else
            {
                left_diagonal = a[i][j] + MINIMUM;
            }

            if((j+1) < m)
            {
                right_diagonal = a[i][j] + dp[i-1][j+1];
            }
            else
            {
                right_diagonal = a[i][j] + MINIMUM;
            }

            dp[i][j] = max(up, max(left_diagonal, right_diagonal)); 
        }
    }

    int mx = dp[n-1][0];
    for(int j=1;j<m;j++)
    {
        mx = max(mx, dp[n-1][j]);
    }
    cout << mx << endl;


    return 0;
}

/*
    TESTCASE : 
        4 4
        1 2 10 4
        100 3 2 1
        1 1 20 2
        1 2 2 1
    ANS : 
        105
*/