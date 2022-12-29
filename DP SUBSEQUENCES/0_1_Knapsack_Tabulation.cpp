#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*W)
// S.C => O(N*W)

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

    vector<vector<int>> dp(n, vector<int> (W + 1, 0)); 

    // BASE CASE
    // for i = 0
    // weight starts from wt[0], not starts form 0.
    for(int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int weight = 0; weight <= W; weight++)
        {
            int not_take = 0 + dp[i-1][weight];
            int take = INT_MIN;
            if(weight >= wt[i])
            {
                take = val[i] + dp[i-1][weight - wt[i]];
            }
            dp[i][weight] = max(take, not_take);
        }
    }
    
    cout << dp[n-1][W] << endl;

    return 0;
}