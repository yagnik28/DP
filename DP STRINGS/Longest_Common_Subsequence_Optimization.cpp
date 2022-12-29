#include<bits/stdc++.h>
using namespace std;

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
    string s, t;
    cin >> s >> t;
    int n = s.size();
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

    cout << cur[m] << endl;

    
    return 0;
}