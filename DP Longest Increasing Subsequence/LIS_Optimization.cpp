#include <bits/stdc++.h>
using namespace std;

// Optimization
// T.C => O(N*N)
// S.C => O(N)

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ahead(n + 1, 0);
    // base case
    for (int prev_i = -1; prev_i <= n - 1; prev_i++)
    {
        ahead[(prev_i + 1)] = 0; // for any prev_i, at i=n, dp[n][prev_i+1] = 0.
    }

    // prev_i has '0' based indexing in dp(ahead) array where prev_i starts from (-1).
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> cur(n + 1, 0);
        for (int prev_i = i - 1; prev_i >= (-1); prev_i--)
        {
            int take = 0;
            if (prev_i == -1 || nums[i] > nums[prev_i])
            {
                take = 1 + ahead[i + 1]; // prev_i = returns the 'i+1'
                // because it keeps '1' index increased in dp(ahead) array.
            }
            int not_take = 0 + ahead[(prev_i + 1)];
            cur[(prev_i + 1)] = max(take, not_take);
        }
        ahead = cur;
    }

    cout << ahead[0] << endl; // ahead[(-1)+1] --> prev_i == -1.

    return 0;
}