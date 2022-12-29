#include<bits/stdc++.h>
using namespace std;

/*
    Recursion :
    T.C => >>O(2^N)
    S.C = >>O(N)
*/

// Memoization : 
// T.C => O(N*N)
// S.C => O(N*N) + O(N)

int rod_cutting(int ind, int n, vector<int> &a, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        return n*a[0];
    }
    if(dp[ind][n] != (-1))
    {
        return dp[ind][n];
    }
    int not_take = 0 + rod_cutting(ind - 1, n, a, dp);
    int take = INT_MIN;
    int rodlegth = ind + 1;
    if(rodlegth <= n)
    {
        take = a[ind] + rod_cutting(ind, n - rodlegth, a, dp);
    }
    return dp[ind][n] = max(take, not_take);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    cout << rod_cutting(n-1, n, a, dp) << endl;
    

    return 0;
}