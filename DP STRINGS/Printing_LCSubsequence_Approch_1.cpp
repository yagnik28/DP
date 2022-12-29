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

    // abcde
    // bdgek
    /*  DP TABLE
        |-> base case column. 
        0 0 0 0 0 0 -> base case row.
          a b c d e
    b   0 0 0 0 0 0 
    d   0 1 1 1 1 1 
    g   0 1 1 1 1 1 
    e   0 1 2 2 2 2 
    k   0 1 2 2 3 |3|  -> our answer for LCS. dp[n][m]
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
            i--;
        }
        else // go to left side
        {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;


    
    return 0;
}