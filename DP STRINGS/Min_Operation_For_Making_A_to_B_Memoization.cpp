#include<bits/stdc++.h>
using namespace std;

// USED Longest Common Subsequence

/*
    Recursion : 
    T.C => O(2^(N+M))
    S.C => O(N+M)
*/

// Memoization : 
// T.C => O(N*M)
// S.C => O(N*M) + O(N+M)

int LCS(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if(i < 0 || j < 0)
    {
        return 0;
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }

    if(s[i] == t[j])
    {
        return dp[i][j] = 1 + LCS(i-1, j-1, s, t, dp);
    }
    return dp[i][j] = max(LCS(i-1, j, s, t, dp), LCS(i, j-1, s, t, dp));
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    int insertions = n - LCS(n-1, m-1, s, t, dp);
    int deletions = m - LCS(n-1, m-1, s, t, dp);
    int operations = insertions + deletions;

    cout << operations << endl;

    return 0;
}