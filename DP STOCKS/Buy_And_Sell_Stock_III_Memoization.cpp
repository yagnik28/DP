#include <bits/stdc++.h>
using namespace std;

// Recursion
// T.C => O(2^N)
// S.C => O(N)

// Memoization 
// T.C => O(N*2*3)
// S.C => O(N*2*3) + O(N)

int f(int ind, int buy, int cap, vector<int> prices, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    if (ind == n)
    {
        return 0;
        // if one share is holded and remains to sell, then it's negative profit already count in "buy == 1" part in 'buy' part.
    }
    if(cap == 0)
    {
        return 0; 
        // we reached the maximum transaction limit.
    }
    if (dp[ind][buy][cap] != -1)
    {
        return dp[ind][buy][cap];
    }

    int profit;

    if (buy == 1) // you can buy this time
    {
        int buy = (-prices[ind]) + f(ind + 1, 0, cap, prices, dp); // i have bought so money reduced from wallet means profit is in negative till we sell it.
        int not_buy = 0 + f(ind + 1, 1, cap, prices, dp);
        profit = max(buy, not_buy);
    }
    else // you can sell only because last time you bought one share.
    {
        int sell = prices[ind] + f(ind + 1, 1, cap-1, prices, dp); // sell this time so you can buy next time so sent 'buy=1'.
        // when we sell then 1 transaction over, so here we sent "cap-1".
        int not_sell = 0 + f(ind + 1, 0, cap, prices, dp);       // we are not selling means already one share holded so sent 'buy=0'.
        profit = max(sell, not_sell);
    }

    return dp[ind][buy][cap] = profit;
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
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));
    cout << f(0, 1, 2, prices, dp) << endl;

    return 0;
}