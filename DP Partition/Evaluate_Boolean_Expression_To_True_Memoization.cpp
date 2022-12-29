#include<bits/stdc++.h>
using namespace std;

/* Recursion :
   T.C => O(Exponential)
   S.C => O(N)
*/

// Memoization
// T.C => O(N*N*2*N)
// S.C => O(N*N*2) + O(N)

#define ll long long
const int mod = 1000000007;

ll f(int i, int j, int isTrue, string s, vector<vector<vector<ll>>> &dp)
{
    if(i > j)
    {
        return 0;
    }
    if(i == j)
    {
        if(isTrue == 1)
        {
            return (s[i] == 'T');
        }
        else
        {
            return (s[i] == 'F');
        }
    }
    if(dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }
    
    ll ways = 0;
    for(int ind=i+1;ind<=j-1;ind = ind + 2)
    {
        ll LT = f(i, ind-1, 1, s, dp);
        ll LF = f(i, ind-1, 0, s, dp);
        ll RT = f(ind+1, j, 1, s, dp);
        ll RF = f(ind+1, j, 0, s, dp);
        
        if(s[ind] == '&')
        {
            if(isTrue == 1)
            {
                ways = (ways + ((LT*RT) % mod)) % mod;
            }
            else
            {
                ways = (ways + (((LF*RF) % mod) + ((LT*RF) % mod) + 
                                ((RT*LF) % mod))) % mod;
            }
        }
        else if(s[ind] == '|')
        {
            if(isTrue == 1)
            {
                ways = (ways + (((LT*RT) % mod) + ((LT*RF) % mod) + 
                                ((RT*LF) % mod))) % mod;
            }
            else
            {
                ways = (ways + ((LF*RF) % mod)) % mod;
            }
        }
        else
        {
            if(isTrue == 1)
            {
                ways = (ways + (((LT*RF) % mod) + ((LF*RT) % mod))) 
                    % mod;
            }
            else
            {
                ways = (ways + (((LF*RF) % mod) + ((LT*RT) % mod))) 
                    % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int main()
{
    int n;
    cin >> n;
    string exp;
    cin >> exp; // it contains 'T', 'F', '&', '|', '^'.
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    cout << f(0, n-1, 1, exp, dp) << endl;

    return 0;
}