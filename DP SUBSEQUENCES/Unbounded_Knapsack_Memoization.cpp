#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^N)
    S.C => >>O(N) 
*/

// Memoization : 
// T.C => O(N*W)
// S.C => O(N*W) + O(N)

int knapsack(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(W >= wt[0])
        {
            return ((W / wt[0])*val[0]);
        }
        else
        {
            return 0;
        }
    }
    if(dp[ind][W] != (-1))
    {
        return dp[ind][W];
    }
    int not_take = 0 + knapsack(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if(W >= wt[ind])
    {
        take = val[ind] + knapsack(ind, W - wt[ind], wt, val, dp);
    }
    return dp[ind][W] = max(take, not_take);
    // we tried all combinations and taken maximum of it.
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for(int i=0;i<n;i++)
    {
        cin >> wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> val[i];
    }
    vector<vector<int>> dp(n, vector<int> (W + 1, -1));

    cout << knapsack(n-1, W, wt, val, dp) << endl;

    return 0;
}