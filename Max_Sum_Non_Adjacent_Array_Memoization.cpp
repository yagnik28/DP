#include<bits/stdc++.h>
using namespace std;

// Memoization.

int max_sum(int ind, vector<int> &dp, vector<int> &a)
{
    if(ind == 0)
    {
        return a[ind];
    }
    if(dp[ind] != (-1))
    {
        return dp[ind];
    }
    if(ind < 0)
    {
        return 0;
    }
    int pick = a[ind] + max_sum(ind - 2, dp, a); // peek = a[i] + dp[i - 2] ==> Tabulation
    int not_pick = 0 + max_sum(ind - 1, dp, a); 
    // not peek so added 0 instead of a[i] and added dp[i -1].
    return dp[ind] = max(pick, not_pick);
} 

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n, -1);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << max_sum(n - 1, dp, a) << endl;

    return 0;
}