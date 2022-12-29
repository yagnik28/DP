#include<bits/stdc++.h>
using namespace std;

// USED LCS(Longest_Common_Subsequence) 
// CHANGE : Input 1 string, and taken a reverse string of the given string 
//          and find LCS of these 2 strings for the length of LPS.
//          Similar, For finding the LPS itself.

/*
    Recursion : 
    T.C => O(2^(N+M))
    S.C => O(N+M)
*/

// Memoization : 
// T.C => O(N*M)
// S.C => O(N*M) + O(N+M)

int LPS(int i, int j, string &s, string &t, vector<vector<int>> &dp)
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
        return dp[i][j] = 1 + LPS(i-1, j-1, s, t, dp);
    }
    return dp[i][j] = max(LPS(i-1, j, s, t, dp), LPS(i, j-1, s, t, dp));
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string t;
    t = s;
    reverse(t.begin(), t.end());
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout << LPS(n-1, m-1, s, t, dp) << endl;

    return 0;
}