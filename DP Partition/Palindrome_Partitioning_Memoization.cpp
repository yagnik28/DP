#include<bits/stdc++.h>
using namespace std;

/* Recursion :
   T.C => O(Exponential)
   S.C => O(N)
*/

// Memoization
// T.C => O(N*N)
// S.C => O(N) + O(N)

bool isPalindrome(int i, int j, string s)
{
    while(i < j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int f(int i, int n, string s, vector<int> &dp)
{
    if(i == n)
    {
        return 0;
    }
    if(dp[i] != -1)
    {
        return dp[i];
    }
    
    int mn = 1e9;
    for(int j=i;j<=n-1;j++)
    {
        if(isPalindrome(i, j, s))
        {
            int cost = 1 + f(j+1, n, s, dp);
            mn = min(mn, cost);
        }
    }
    return dp[i] = mn;
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> dp(n, -1);
    cout << f(0, n, str, dp) - 1 << endl;

    return 0;
}