#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^(N+M))
    S.C => O(N+M)
*/

// Optimization : 
// T.C => O(N*M)
// S.C => O(M)

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    // USING only 'prev'

    vector<int> prev(m+1, 0);

    // BASE CASE
    prev[0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(s[i - 1] == t[j - 1])
            {
                prev[j] = prev[j] + prev[j-1];
            }
            // Not requirement of else condition.
            // else
            // {
            //     prev[j] = prev[j];
            // }
        }
    }

    cout << prev[m] << endl;

    return 0;
}

/*
    USING 'prev' and 'cur'
    vector<int> prev(m+1, 0), cur(m+1, 0);

    // BASE CASE
    prev[0] = cur[0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                cur[j] = prev[j] + prev[j-1];
            }
            else
            {
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }

    cout << prev[m] << endl;

*/

