#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin >> s;
    cin >> t;
    int n, m;
    n = s.size();
    m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = 0; // string 's' is at horizontal on 2-D Dp.
    }
    for(int i=1;i<=m;i++)
    {
        dp[0][i] = 0; // string 't' is at vertical on 2-D Dp.
    }
    int mx = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                mx = max(mx, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << mx << endl;

    return 0;
}