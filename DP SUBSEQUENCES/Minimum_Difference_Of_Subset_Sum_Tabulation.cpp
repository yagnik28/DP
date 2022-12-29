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
    int n;
    cin >> n;
    vector<int> a(n);
    int TotalSum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        TotalSum += a[i];
    }

    int target = TotalSum;

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

    int mn = 1e9;
    for(int i=0;i<=(TotalSum/2);i++)
    {
        if(dp[n-1][i] == 1)
        {
            int s1 = i;
            int s2 = TotalSum - i;
            mn = min(mn, abs(s2 - s1));
        }
    }

    cout << mn << endl;

    return 0;
}