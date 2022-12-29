#include<bits/stdc++.h>
using namespace std;


/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Memoization : 
// T.C => O(N*target)
// S.C => O(N*target) + O(N)

bool target_sum(int i, int target, vector<int> &a, vector<vector<int>> &dp)
{
    if(target == 0)
    {
        return 1; // 1 = true
    }
    if(i == 0)
    {
        return (a[0] == target);
    }
    if(dp[i][target] != (-1))
    {
        return dp[i][target];
    }
    bool not_take = target_sum(i-1, target, a, dp);
    bool take = 0; // 0 = false
    if(target >= a[i])
    {
        take = target_sum(i-1, target - a[i], a, dp);
    }
    return dp[i][target] = (take | not_take);
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int> (target + 1, -1)); 
    cout << target_sum(n-1, target, a, dp) << endl;

    return 0;
}