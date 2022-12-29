#include<bits/stdc++.h>
using namespace std;

// Used Longest_Common_Subsequence_Tabulation

// Tabulation : 
// T.C => O(N*M)
// S.C => O(N*M)

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    // BASE CASE
    for(int j=0;j<=m;j++)
    {
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // brute
    // groot
    /*  DP TABLE
        |-> base case column. 
        0 0 0 0 0 0 -> base case row.
          g r o o t
    b   0 0 0 0 0 0 
    r   0 0 1 1 1 1 
    u   0 0 1 1 1 1 
    t   0 0 1 1 1 2 
    e   0 0 1 1 1 |2| -> our answer for LCS. dp[n][m] 
    */    

    int length_of_LCS = dp[n][m];
    string ans = "";

    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s[i - 1] == t[j - 1]) // go to diagonal
        {
            ans += s[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) // go to up side
        {
            ans += s[i - 1];
            i--;
        }
        else // go to left side
        {
            ans += t[j - 1];
            j--;
        }
    }

    while(i > 0) // remaining string 's'
    {
        ans += s[i - 1];
        i--;
    }

    while(j > 0) // remaining string 't'
    {
        ans += t[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;


    
    return 0;
}