#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^N)
    S.C => >>O(N) --> May be go to O(target) OR go to beyond it.
*/

// Memoization
// T.C => O(N*target)
// S.C => O(N*target) + O(target)

/*** 
    (i) Any no.of Times OR (ii) Multiple Times then do not move to next, stay on that index.
    Here, Do this for "take" part.
***/

int min_coins(int i, int target, vector<int> &a, vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if((target % a[0]) == 0)
        {
            return target / a[0];
        }
        else
        {
            return 1e9;
        }
    }
    if(dp[i][target] != (-1))
    {
        return dp[i][target];
    }
    int not_take = 0 + min_coins(i-1, target, a, dp);
    int take = INT_MAX;
    if(target >= a[i])
    {
        take = 1 + min_coins(i, target - a[i], a, dp); 
        // stay on index 'i' till target become smaller then the a[i].
    }
    return dp[i][target] = min(take, not_take);
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int> (target + 1, -1));

    int ans = min_coins(n-1, target, a, dp);
    if(ans >= 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}