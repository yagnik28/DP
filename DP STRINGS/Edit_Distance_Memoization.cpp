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

int edit_distance(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if(i < 0)
    {
        return j+1;
    }
    if(j < 0)
    {
        return i+1;
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }

    if(s[i] == t[j])
    {
        return dp[i][j] = 0 + edit_distance(i-1, j-1, s, t, dp);
    }
    else
    {
        return dp[i][j] = 1 + min(edit_distance(i, j-1, s, t, dp), 
                                    min(edit_distance(i-1, j, s, t, dp), 
                                            edit_distance(i-1, j-1, s, t, dp)));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout << edit_distance(n-1, m-1, s, t, dp) << endl;

    return 0;
}