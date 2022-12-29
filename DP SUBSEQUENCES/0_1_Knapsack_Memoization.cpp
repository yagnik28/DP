#include<bits/stdc++.h>
using namespace std;


/*
    Recursion : 
    T.C => O(N*K)
    S.C => O(N)
*/

// Memoization : 
// T.C => O(N*W)
// S.C => O(N*W) + O(N)

int knapsack(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if(W >= wt[0])
        {
            return val[0];
        }
        return 0;
    }
    if(dp[i][W] != (-1))
    {
        return dp[i][W];
    }
    int not_take = 0 + knapsack(i-1, W, wt, val, dp);
    int take = INT_MIN;
    if(W >= wt[i])
    {
        take = val[i] + knapsack(i-1, W - wt[i], wt, val, dp);
    }
    return dp[i][W] = max(take, not_take);
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