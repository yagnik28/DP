#include<bits/stdc++.h>
using namespace std;

// Tabulation is always reverse process of Memoization.

// T.C => O(N*N) => O((N*(N+1))/2) => O(1 + 2 + ... + N)
// S.C => O(N*N) -> DP Array Space only.

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (n, -1));
    // BASE CASE
        for(int j=0;j<n;j++)
        {
            dp[n-1][j] = a[n-1][j];
        }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down = a[i][j] + dp[i+1][j]; // i = n-2, i+1 = n-1 means for dp[i][j] it uses dp[i+1][j],
                                             // means for dp[n-2][j] uses dp[n-1][j]
            int diagonal = a[i][j] + dp[i+1][j+1]; // same here as above 
            dp[i][j] = min(down, diagonal);
        }
    }
    cout << dp[0][0] << endl;

    return 0;
}

/*
    TESTCASE : 
        4
        1
        2 3
        3 6 7
        8 9 6 10
    ANS : 
        14
*/