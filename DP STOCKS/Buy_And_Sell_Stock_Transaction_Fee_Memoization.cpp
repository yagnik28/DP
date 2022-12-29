#include <bits/stdc++.h>
using namespace std;

// CHANGE : Either at Buy part Or at Sell part deduct the Transaction fee from your money.

// Recursion
// T.C => O(2^N)
// S.C => O(N)

// Memoization 
// T.C => O(N*2)
// S.C => O(N*2) + O(N)

int f(int ind, int buy, int fee, vector<int> prices, vector<vector<int>> &dp)
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
        int buy = (-prices[ind]) + f(ind + 1, 0, fee, prices, dp); // i have bought so money reduced from wallet means profit is in negative till we sell it.
        int not_buy = 0 + f(ind + 1, 1, fee, prices, dp);
        profit = max(buy, not_buy);
    }
    else // you can sell only because last time you bought one share.
    {
        int sell = (prices[ind] - fee) + f(ind + 1, 1, fee, prices, dp); // fee deducted here.
        int not_sell = 0 + f(ind + 1, 0, fee, prices, dp);       
        profit = max(sell, not_sell);
    }

    return dp[ind][buy] = profit;
}

int main()
{
    int n, fee;
    cin >> n >> fee;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }
    vector<vector<int>> dp(n, vector<int> (2, -1));
    cout << f(0, 1, fee, prices, dp) << endl;

    return 0;
}