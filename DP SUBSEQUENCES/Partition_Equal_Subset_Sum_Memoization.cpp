#include<bits/stdc++.h>
using namespace std;


/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Memoization : 
// T.C => O(N*ReqSum)
// S.C => O(N*ReqSum) + O(N)

bool Equal_sum(int i, int ReqSum, vector<int> &a, vector<vector<int>> &dp)
{
    if(ReqSum == 0)
    {
        return 1; // 1 = true
    }
    if(i == 0)
    {
        return (a[0] == ReqSum);
    }
    if(dp[i][ReqSum] != (-1))
    {
        return dp[i][ReqSum];
    }
    bool not_take = Equal_sum(i-1, ReqSum, a, dp);
    bool take = 0; // 0 = false
    if(ReqSum >= a[i])
    {
        take = Equal_sum(i-1, ReqSum - a[i], a, dp);
    }
    return dp[i][ReqSum] = (take | not_take);
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
    int ReqSum = TotalSum / 2;
    if(TotalSum % 2 == 1)
    {
        cout << false << endl;
    }
    else
    {
        vector<vector<int>> dp(n, vector<int> (ReqSum + 1, -1)); 
        cout << Equal_sum(n-1, ReqSum, a, dp) << endl;
    }

    

    return 0;
}