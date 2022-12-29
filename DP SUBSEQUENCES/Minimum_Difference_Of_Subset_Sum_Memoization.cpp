#include<bits/stdc++.h>
using namespace std;

/*** This is not working due to recursion But Tabulation & Optimization works Properly. ***/
// May be problem is in dp array when we call it but change it not be occured in dp array.

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
    
    vector<vector<int>> dp(n, vector<int> (target + 1, -1)); 

    bool temp = target_sum(n-1, target, a, dp);

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