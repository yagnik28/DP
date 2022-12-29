#include <bits/stdc++.h>
using namespace std;

// CHANGE : Either at Buy part Or at Sell part deduct the Transaction fee from your money.

// Tabulation 
// T.C => O(N*2)
// S.C => O(N*2)

int main()
{
    int n, fee;
    cin >> n >> fee;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    // base case
    dp[n][0] = dp[n][1] = 0; // when whole array travesed after that nothing is in profit.

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        for (int prev_buy = 0; prev_buy <= 1; prev_buy++)
        {
            if (prev_buy == 1)
            {
                int buy = (-prices[i] - fee) + dp[i + 1][0]; // fee deducted here.
                int not_buy = 0 + dp[i + 1][1];
                dp[i][1] = profit = max(buy, not_buy);
            }
            else
            {
                int sell = prices[i] + dp[i + 1][1];
                int not_sell = 0 + dp[i + 1][0];
                dp[i][0] = profit = max(sell, not_sell);
            }
        }
    }
    cout << dp[0][1] << endl;

    return 0;
}