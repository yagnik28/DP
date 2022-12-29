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
    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

    // 1 Based Indexing for DP Array But for Strings 0 Based Indexing.

    // BASE CASE
    dp[0][0] = true;
    for(int j=1;j<=m;j++)
    {
        dp[0][j] = false;
    }
    for(int i=1;i<=n;i++)
    {
        bool flag = true;
        for(int k=1;k<=i;k++)
        {
            if(s[i-1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1] || s[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(s[i - 1] == '*')
            {
                dp[i][j] = (dp[i - 1][j] | dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}