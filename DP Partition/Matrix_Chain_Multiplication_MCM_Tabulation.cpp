#include<bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*N*N)
// S.C => O(N*N)

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int> (n, 0));
    // base case
    for(int i=1;i<=n-1;i++)
    {
        dp[i][i] = 0;
    }
    
    for(int i=n-1;i>=1;i--) 
    {
        for(int j=i+1;j<=n-1;j++) // 'j' always stays at right side of 'i'.
        {
            int mn = 1e9;
            for(int k=i;k<=j-1;k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mn = min(mn, steps);
            }
            dp[i][j] = mn;
        }
    }
    
    cout << dp[1][n-1] << endl;

    return 0;
}