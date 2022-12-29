#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*N)
// S.C => O(N*N)

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // base case
    for (int prev_i = -1; prev_i <= n - 1; prev_i++)
    {
        dp[n][(prev_i + 1)] = 0; // for any prev_i, at i=n, dp[n][prev_i+1] = 0.
    }

    // prev_i has '0' based indexing in dp array where prev_i starts from (-1).
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev_i = i - 1; prev_i >= (-1); prev_i--)
        {
            int take = 0;
            if (prev_i == -1 || nums[i] > nums[prev_i])
            {
                take = 1 + dp[i + 1][i + 1]; // prev_i = return the 'i+1'
                // because it keeps '1' index increased.
            }
            int not_take = 0 + dp[i + 1][(prev_i + 1)];
            dp[i][(prev_i + 1)] = max(take, not_take);
        }
    }

    cout << dp[0][0] << endl; // dp[0][(-1)+1] --> prev_i == -1.

    return 0;
}