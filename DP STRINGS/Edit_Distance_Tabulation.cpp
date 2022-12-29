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

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    // 1 Based Indexing for DP Array But for strings 0 Based Indexing.

    // BASE CASE
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j] = j;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                // insertions -> dp[i][j - 1], stay on 'i', 
                //            and add hypothetically a character at 'i+1' and move to 'j-1'.
                // deletion -> dp[i - 1][j], move to next 'i'(i-1) and delete element at 'i',
                //            But stay on 'j' for next comparison.
                // replace -> dp[i - 1][j - 1], move to next 'i'(i-1) and replace it to t[j],
                //            Now, by replacing it become equal so move 'j'(j-1).
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}