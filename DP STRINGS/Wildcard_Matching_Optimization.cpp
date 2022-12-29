#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^(N+M))
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

    vector<bool> prev(m+1, false), cur(m+1, false);

    // 1 Based Indexing for DP Array But for Strings 0 Based Indexing.

    // BASE CASE
    prev[0] = true;
    for(int j=1;j<=m;j++)
    {
        prev[j] = false;
    }

    for(int i=1;i<=n;i++)
    {
        // Remaining Base Case
            bool flag = true;
            for(int k=1;k<=i;k++)
            {
                if(s[i-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            cur[0] = flag; 
            // for (j=0) for every 'i'(for every 'row'), 
            // we updating the column of that row('i'), which is cur[0].

        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1] || s[i - 1] == '?')
            {
                cur[j] = prev[j - 1];
            }
            else if(s[i - 1] == '*')
            {
                cur[j] = (prev[j] | cur[j - 1]);
            }
            else
            {
                cur[j] = false;
            }
        }
        prev = cur;
    }

    cout << prev[m] << endl;

    return 0;
}