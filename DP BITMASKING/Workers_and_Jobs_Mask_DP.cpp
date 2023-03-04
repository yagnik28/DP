#include<bits/stdc++.h>
using namespace std;

// Recursion :
// T.C => O(N!)

// T.C => O(N*N*2^N)
// S.C => O(N*2^N)

// Approach : For every Job try to assign People and for set of people 
//            use a Integer as bitmask to denote 'n' integers using 'n' bit number.
//            For bit = 1, people have not assigned job yet, we can assign current job.
//            For bit = 0, people have assigned job before, Now we can not assign any job.
//            "Mask" => It represents the set of people at any state "i" which are free to do job which has bit = 1.  

int dp_mask(int i, int mask, vector<vector<int>> &work, vector<vector<int>> &dp)
{
    int n = work.size();
    if(i == n) return 0;

    if(dp[i][mask] != -1)
    {
        return dp[i][mask];
    }

    int mn = 1e9;
    for(int j = 0; j < n; j++)
    {
        if(mask & (1 << j))
        {
            mn = min(mn, dp_mask(i + 1, (mask & ~(1 << j)), work, dp) + work[i][j]);
        }
    }
    return dp[i][mask] = mn;
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> work(n, vector<int> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> work[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> ((1 << n), -1));

    int mask = (1 << n) - 1; // 111111...... every ==> people is available.

    int ans = dp_mask(0, mask, work, dp);

    cout << ans << endl;

    return 0;
}

/*
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4 
*/