#include <bits/stdc++.h>
using namespace std;

// Using one Array of transaction_No which keeps track of Buy & Sell of stock as index number
// Like, B S B S B S ...... B S --> 0 1 2 3 4 5 ...... (2*k-2) (2*k-1).

// Recursion
// T.C => O(2^N)
// S.C => O(N)

// Memoization 
// T.C => O(N*2*k)
// S.C => O(N*2*k) + O(N)

int f(int ind, int transNo, int k, vector<int> prices, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (ind == n)
    {
        return 0;
        // if one share is holded and remains to sell, then it's negative profit already count in "buy == 1" part in 'buy' part.
    }
    if(transNo == 2*k)
    {
        return 0; 
        // we reached the maximum transaction limit.
    }
    if (dp[ind][transNo] != -1)
    {
        return dp[ind][transNo];
    }

    int profit;

    if (transNo % 2 == 0) // you can buy this time
    {
        int buy = (-prices[ind]) + f(ind + 1, transNo+1, k, prices, dp); 
        int not_buy = 0 + f(ind + 1, transNo, k, prices, dp);
        profit = max(buy, not_buy);
    }
    else // you can sell only because last time you bought one share.
    {
        int sell = prices[ind] + f(ind + 1, transNo+1, k, prices, dp); 
        int not_sell = 0 + f(ind + 1, transNo, k, prices, dp);       
        profit = max(sell, not_sell);
    }

    return dp[ind][transNo] = profit;
}

int main()
{
    int n, k;
    cin >> n >> k; 
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }
    // k = atmost k transaction can occur.
    vector<vector<int>> dp(n+1, vector<int> (2*k+1,-1));
    cout << f(0, 0, k, prices, dp) << endl;

    return 0;
}