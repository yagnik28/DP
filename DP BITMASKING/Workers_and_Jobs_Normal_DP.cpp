#include<bits/stdc++.h>
using namespace std;

// Approach : For every person try every jobs including that current job number is not taken by any people before.

int f(int i, int j, vector<int> &vis, vector<vector<int>> &work, vector<vector<int>> &dp)
{
    int n = work.size();
    if(i == n) return 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mn = 1e9;
    for(int k = 0; k < n; k++)
    {
        if(!vis[k])
        {
            vis[k] = 1;
            mn = min(mn, f(i + 1, k, vis, work, dp) + work[i][k]);
            vis[k] = 0;
        }
    }
    return dp[i][j] = mn;
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
    vector<vector<int>> dp(n, vector<int> (n, -1));
    vector<int> vis(n, 0);
    int mn = 1e9;
    for(int j = 0; j < n; j++)
    {
        vis[j] = 1;
        mn = min(mn, f(1, j, vis, work, dp) + work[0][j]);
        vis[j] = 0;
    }
    cout << mn << endl;

    return 0;
}

/*
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4 
*/