#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*K)
// S.C => O(N*K)

int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int> (K + 1, 0)); 

    // BASE CASE
    if(a[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }
    if(a[0] != 0 && a[0] <= K)
    {
        dp[0][a[0]] = 1; 
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=K;j++)
        {
            int not_take = dp[i-1][j];
            int take = 0; // 0 = false
            if(j >= a[i])
            {
                take = dp[i-1][j - a[i]];
            }
            dp[i][j] = (take + not_take);
        }
    }

    cout << dp[n-1][K] << endl;

    return 0;
}