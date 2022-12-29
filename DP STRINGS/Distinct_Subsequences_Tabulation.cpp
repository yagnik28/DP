#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^(N+M))
    S.C => O(N+M)
*/

// Tabulation : 
// T.C => O(N*M)
// S.C => O(N*M)

int dist_subsequence(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if(j < 0) 
    {
        return 1;
        // if 't' gets over then definitely return '1', 
        // because we found a subsequence in 's' which is equal to 't'. 
    }
    if(i < 0)
    {
        return 0;
        // if 's' gets over then we definitely return '0',
        // because (j < 0) is not executed so 't' is remaining but 's' is over,
        // so, no subsequence found at this time.
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }

    if(s[i] == t[j])
    {
        return dp[i][j] = dist_subsequence(i-1, j, s, t, dp) + dist_subsequence(i-1, j-1, s, t, dp);
        // it means s[i] == t[j] still, 
        // either move to next character of 's' to match current character of 't',
        // OR move to next character of 's' to match the next character of 't'.
    }
    else
    {
        return dp[i][j] = dist_subsequence(i-1, j, s, t, dp);
        // it means characters are not equal,
        // so, move to next character of 's' to match the current character of 't'.
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    // 1 Based Indexing for DP Array But 0 Based Indexing for strings.


    // BASE CASE
    for(int i=0;i<=n;i++){ dp[i][0] = 1; }
    for(int j=1;j<=m;j++){ dp[0][j] = 0; }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}