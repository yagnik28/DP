#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*2*k)
// S.C => O(N*2*k)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2*k+1, -1));

    // base case
    // (i) ind = n => transNo can be anything.
    for(int transNo=0;transNo<=2*k;transNo++)
    {
        dp[n][transNo] = 0;
    }
    // (ii) transNo = 2*k => ind can be anything.
    for(int ind=0;ind<=n;ind++)
    {
        dp[ind][2*k] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        for (int transNo=2*k-1;transNo>=0;transNo--)
        {
            if (transNo % 2 == 0) // Buy Option
            {
                int buy = (-prices[i]) + dp[i + 1][transNo+1];
                int not_buy = 0 + dp[i + 1][transNo];
                dp[i][transNo] = profit = max(buy, not_buy);
            }
            else
            {
                int sell = prices[i] + dp[i + 1][transNo+1];
                int not_sell = 0 + dp[i + 1][transNo];
                dp[i][transNo] = profit = max(sell, not_sell);
            }
        }
    }
    cout << dp[0][0] << endl;

    return 0;
}