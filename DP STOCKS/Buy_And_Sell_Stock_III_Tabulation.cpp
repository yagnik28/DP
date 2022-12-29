#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*2*3)
// S.C => O(N*2*3)

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

    // base case
    for (int ind = 0; ind <= n - 1; ind++) // for cap==0 then ind & buy can be anything.
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            dp[ind][buy][0] = 0; // if(cap==0){return 0;}
        }
    }
    for (int buy = 0; buy <= 1; buy++) // for ind==n then buy & cap can be anything.
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            dp[n][buy][cap] = 0; // if(n==0){return 0;}
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        for (int prev_buy = 0; prev_buy <= 1; prev_buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (prev_buy == 1)
                {
                    int buy = (-prices[i]) + dp[i + 1][0][cap];
                    int not_buy = 0 + dp[i + 1][1][cap];
                    dp[i][prev_buy][cap] = profit = max(buy, not_buy);
                }
                else
                {
                    int sell = prices[i] + dp[i + 1][1][cap - 1];
                    int not_sell = 0 + dp[i + 1][0][cap];
                    dp[i][prev_buy][cap] = profit = max(sell, not_sell);
                }
            }
        }
    }
    cout << dp[0][1][2] << endl;

    return 0;
}