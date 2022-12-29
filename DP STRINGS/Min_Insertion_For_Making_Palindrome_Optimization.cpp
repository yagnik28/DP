#include<bits/stdc++.h>
using namespace std;

// USED LCS(Longest_Common_Subsequence) 
// CHANGE : Input 1 string, and taken a reverse string of the given string 
//          and find LCS of these 2 strings for the length of LPS.
//          Similar, For finding the LPS itself.
//          After that other then LPS, should be added into the given string 
//          then it will become Palindromic with Minimum Insertions.

/*
    Recursion : 
    T.C => O(2^(N+M))
    S.C => O(N+M)
*/

// Optimization : 
// T.C => O(N*M)
// S.C => O(M)

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string t;
    t = s;
    reverse(t.begin(), t.end());
    int m = t.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    
    // BASE CASE
    for(int j=0;j<=m;j++)
    {
        prev[j] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                cur[j] = 1 + prev[j - 1];
            }
            else
            {
                cur[j] = 0 + max(prev[j], cur[j - 1]);
            }
        }
        prev = cur;
    }

    int LPS = cur[m];

    cout << (s.size() - LPS) << endl;

    
    return 0;
}