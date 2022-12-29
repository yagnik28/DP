#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^(N+M))
    S.C => O(N+M)
*/

// Memoization : 
// T.C => O(N*M)
// S.C => O(N*M) + O(N+M)

bool wildcard_matching(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if(i < 0 && j < 0)
    {
        return true;
    }
    if(i < 0 && j >= 0)
    {
        return false;
    }
    if(j < 0 && i >= 0)
    {
        // for s2 gets over but s1 remains then if all elements are '*',
        // then all '*' becomes empty and makes s == t then true, otherwise false.
        bool flag = true;
        for(int k=1;k<=i;k++)
        {
            if(s[i] != '*')
            {
                return false;
            }
        }
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }

    if(s[i] == t[j] || s[i] == '?')
    {
        // if both characters equal then reduce 'i' & 'j' both.
        return dp[i][j] = wildcard_matching(i-1, j-1, s, t, dp);
    }
    if(s[i] == '*')
    {
        // for '*' it can become empty OR one by one it can reduce by 1 element 
        // and by reducing one element it still stays '*',
        // and next time these thing repeats as recursion.
        return dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
    }
    return dp[i][j] = false;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout << wildcard_matching(n-1, m-1, s, t, dp) << endl;

    return 0;
}