#include<bits/stdc++.h>
using namespace std;

// Memoization Method Top-Down Approch. ==> T.C O(N), S.C ==> O(N) + O(N).

// Tabulation can be done same as for previous Frog_Jump. ==> T.C O(N), S.C ==> O(N).

int min_energy(int ind, int k, vector<int> &dp, vector<int> &a)
{
    if(ind == 0)
    {
        return 0;
    }
    if(dp[ind] != (-1))
    {
        return dp[ind];
    }
    int minsteps = INT_MAX;
    for(int i=1;i<=k;i++)
    {
        int jump = INT_MAX;
        if(ind - i >= 0)
        {
            jump = min_energy(ind - i, k, dp, a) + abs(a[ind] - a[ind - i]);
        }
        minsteps = min(minsteps, jump);
    }
    return dp[ind] = minsteps;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n, -1);
    cout << min_energy(n - 1, k, dp , a);

    return 0;
}