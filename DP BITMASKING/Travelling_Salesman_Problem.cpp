#include<bits/stdc++.h>
using namespace std;

// Recursion :
// T.C => O(N!)

// T.C => O(N*N*2^N)
// S.C => O(N*2^N)

// Approach : Start from City = 0, and go to all possible next cities and take minimum of it, 
//            including the return back to city = 0 case.

// DP(i, S) => 'i' -> current city, 'S' -> set of cities which are remaining to visit
// DP(i, S) -> Minimum distance needed to travel from city 'i' to all Remaining cities in set 'S' 
//             and get back to city = 0.

int f(int i, int mask, vector<vector<int>> &dist, vector<vector<int>> &dp)
{
    int n = dist.size();
    if(mask == 0) 
    {
        return dist[i][0];
    }
    if(dp[i][mask] != -1)
    {
        return dp[i][mask];
    }

    int mn = INT_MAX;
    for(int j = 0; j < n; j++)
    {
        if(mask & (1 << j))
        {
            mn = min(mn, dist[i][j] + f(j, (mask ^ (1 << j)), dist, dp)); 
            // mask ^ (1 << j) == mask & ~(1 << j) => just making 'j' th bit to '0'.
        }
    }
    return dp[i][mask] = mn;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> ((1 << n), -1));
    
    int ans = f(0, (1 << n) - 2, dist, dp);
    // (1 << n) - 2 => 1111......10 => because we are at city = 0, so we don't go to city = 0, that's why.

    cout << ans << endl;

    return 0;
}