#include <bits/stdc++.h>
using namespace std;

// Tabulation 
// T.C => O(N*2)
// S.C => O(N*2)

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(2, -1));

    // base case
    // when whole array travesed after that nothing is in profit.
    dp[n][0] = dp[n][1] = 0;
    dp[n+1][0] = dp[n+1][1] = 0; // added because of cooldown condition in which we are doing 'i+2' so for 'n-1' it can go upto 'n+1'.

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        for (int prev_buy = 0; prev_buy <= 1; prev_buy++)
        {
            if (prev_buy == 1)
            {
                int buy = (-prices[i]) + dp[i + 1][0];
                int not_buy = 0 + dp[i + 1][1];
                dp[i][1] = profit = max(buy, not_buy);
            }
            else
            {
                int sell = prices[i] + dp[i + 2][1]; // for sell part we skip 'i+1' part becauseof cooldown condition in which we are selling stock at 'i' so we can't buy at 'i+1'.
                int not_sell = 0 + dp[i + 1][0];
                dp[i][0] = profit = max(sell, not_sell);
            }
        }
    }
    cout << dp[0][1] << endl;

    return 0;
}