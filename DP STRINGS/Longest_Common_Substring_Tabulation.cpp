#include<bits/stdc++.h>
using namespace std;

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

    // BASE CASE
    for(int j=0;j<=m;j++)
    {
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                // for (i, j) if (i-1,j-1) is not same(0) so (i, j) will be '1' now. 
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0; // not same case.
            }
        }
    }

    /*  DP TABLE
        |-> base case column.
                 a    b     z     d
    (m)     0    0    0     0     0 -> base case row.
        a   0    1    0     0     0 
        b   0    0    2     0     0 
        c   0    0    0     0     0 
        d   0    0    0     0     1 --> (n, m).
      (n)
   (nth line)
   
   for (1, 1) = (i, j), check if(s[i-1] == t[j-1]) -> here, YES  (s[0] = 'a' & t[0] = 'a' --> s[i-1] = t[j-1])
   then dp[i][j] = 1 + 0 --> (because dp[i-1][j-1] = 0 --> (i-1, j-1)=(0, 0) --> here)
   
   simillarly for every index.
   
   for (n-1, m-1) -> here -> (s[i] == t[j]) -> YES, then dp[n-1][m-1] = 1 + 0, 
   (because, dp[n][m] = 0)
   
   for(n, m) -> here -> (s[i] = t[j]) -> YES, then dp[n][m] = 1 + 1, 
   (because dp[n-1][m-1] = 1) from formula (dp[i][j] = 1 + dp[i+1][j+1]). 

   store answer of dp[i][j] evrytime with maximum value = ans.
   return the 'ans'.

    */

    cout << ans << endl;

    
    return 0;
}