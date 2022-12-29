#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*target)
// S.C => O(N*target)

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int> (target + 1, 0)); 

    // BASE CASE
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 1; // for target == 0 every index is true.
    }
    dp[0][a[0]] = 1; // at idex i = 0, target = a[0] and yes it is posible -> dp[0][a[0]] = 1.

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            bool not_take = dp[i-1][j];
            bool take = 0; // 0 = false
            if(j >= a[i])
            {
                take = dp[i-1][j - a[i]];
            }
            dp[i][j] = (take | not_take);
        }
    }

    cout << dp[n-1][target] << endl;

    return 0;
}