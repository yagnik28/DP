#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*N*N)
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
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    // now size of array increased to 'n+2' after adding '1' and '1'.
    // now, first index is '0' and last index if 'n+1'
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    // base case
    // (i > j) => return 0;
    for (int j = 0; j <= n; j++)
    {
        for (int i = j + 1; i <= n; i++)
        {
            dp[i][j] = 0;
        }
    }

    // array index range => [0, n+1]
    // excluding 1 & 1 range => [1, n]

    // for finding f(i, ind-1) => for i=0 and ind=i, ind-1 = (-1)
    // that'why we are  excluding i=0 and starting from i=1.

    // for f(ind+1, j) => for j=n+1 and ind=j, ind+1 = n+2 out of array
    // that's why we are excluding j=n+1 and end up at j=n.

    for (int i = n + 1; i >= 1; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            int mx = 0;
            for (int ind = i; ind <= j; ind++)
            {
                int coins = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mx = max(mx, coins);
            }
            dp[i][j] = mx;
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}