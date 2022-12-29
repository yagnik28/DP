#include<bits/stdc++.h>
using namespace std;


/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Memoization : 
// T.C => O(N*K)
// S.C => O(N*K) + O(N)

int K_sum(int i, int K, vector<int> &a, vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if(K == 0 && a[0] == 0)
        {
            return 2;
        }
        if(K == 0 || K == a[0])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[i][K] != (-1))
    {
        return dp[i][K];
    }
    int not_take = K_sum(i-1, K, a, dp);
    int take = 0; // 0 = false
    if(K >= a[i])
    {
        take = K_sum(i-1, K - a[i], a, dp);
    }
    return dp[i][K] = (take + not_take);
}

int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int> (K + 1, -1)); 
    cout << K_sum(n-1, K, a, dp) << endl;

    return 0;
}