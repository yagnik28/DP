#include<bits/stdc++.h>
using namespace std;

// Tabualtion
// T.C => O(N*N*2*N)
// S.C => O(N*N*2)

#define ll long long
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    string exp;
    cin >> exp; // it contains 'T', 'F', '&', '|', '^'.
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    // base case
    for(int j=0;j<=n-1;j++)
    {
        for(int i=j+1;i<=n-1;i++)
        {
            dp[i][i][0] = 0;
            dp[i][i][1] = 0;
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }
    
     for(int i=n-1; i>=0; i--)
     {
        for(int j=i+1; j<n; j++)
        {
            for(int isTrue=0; isTrue <=1; isTrue++)
            {
                ll ways=0;
                for(int ind =i+1; ind <= j-1; ind=ind+2)
                {
                    ll LT = dp[i][ind-1][1];
                    ll LF = dp[i][ind-1][0];
                    ll RT = dp[ind+1][j][1];
                    ll RF = dp[ind+1][j][0];
                    if(exp[ind] == '&')
                    {
                        if(isTrue) ways = (ways + (LT * RT)%mod)%mod;
                        else ways = (ways + (LT*RF)%mod + (LF*RF)%mod +
                                     (LF*RT)%mod)%mod;
                    }
                    else if(exp[ind] == '|')
                    {
                        if(isTrue) ways = (ways + (LT*RT)%mod + 
                                           (LT*RF)%mod + 
                                           (LF*RT)%mod)%mod;
                        else ways = (ways + (LF*RF)%mod)%mod;
                    }
                    else
                    {
                        if(isTrue) ways = (ways + (LT*RF)%mod + 
                                           (LF*RT)%mod)%mod;
                        else ways = (ways + (LT*RT)%mod + 
                                     (LF*RF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    
    cout << dp[0][n-1][1] << endl;

    return 0;
}