#include<bits/stdc++.h>
using namespace std;

// USED Longest Common Subsequence

/*
    Recursion : 
    T.C => O(2^(N+M))
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
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    // for base case, in dp array we are storing with '1' based indexing 
    // and as in memoization 'i' & 'j' goes to (-1) so here it will go to (0).

    // BASE CASE
    for(int j=0;j<=m;j++)
    {
        dp[0][j] = 0;
         // j => 0 -> m (not m-1 but upto m, 1->m is storing lengths 
         //               and 0 is for base case)
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
         // i => 0 -> n (not n-1 but upto n, 1->n is storing lengths 
         //               and 0 is for base case)
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

    int insertions = n - dp[n][m];
    int deletions = m - dp[n][m];
    int operations = insertions + deletions;

    cout << operations << endl;

    
    return 0;
}