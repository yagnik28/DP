#include <bits/stdc++.h>
using namespace std;

// Recursion
// T.C => O(2^N)
// S.C => O(N)

// Memoization 
// T.C => O(N*2)
// S.C => O(N*2) + O(N)

int f(int ind, int buy, vector<int> prices, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (ind == n)
    {
        return 0;
        // if one share is holded and remains to sell, then it's negative profit already count in "buy == 1" part in 'buy' part.
    }
    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    int profit;

    if (buy == 1) // you can buy this time
    {
        int buy = (-prices[ind]) + f(ind + 1, 0, prices, dp); // i have bought so money reduced from wallet means profit is in negative till we sell it.
        int not_buy = 0 + f(ind + 1, 1, prices, dp);
        profit = max(buy, not_buy);
    }
    else // you can sell only because last time you bought one share.
    {
        int sell = prices[ind] + f(ind + 1, 1, prices, dp); // sell this time so you can buy next time so sent 'buy=1'.
        int not_sell = 0 + f(ind + 1, 0, prices, dp);       // we are not selling means already one share holded so sent 'buy=0'.
        profit = max(sell, not_sell);
    }

    return dp[ind][buy] = profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }
    vector<vector<int>> dp(n, vector<int> (2, -1));
    cout << f(0, 1, prices, dp) << endl;

    return 0;
}