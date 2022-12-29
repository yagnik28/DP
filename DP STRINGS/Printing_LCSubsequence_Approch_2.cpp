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

    string ans = "";

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
                ans += s[i - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << ans << endl;


    
    return 0;
}