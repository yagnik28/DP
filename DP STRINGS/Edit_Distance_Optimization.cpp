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
    vector<int> prev(m+1, 0), cur(m+1, 0);

    // 1 Based Indexing for DP Array But for strings 0 Based Indexing.

    // BASE CASE
    for(int j=0;j<=m;j++)
    {
        prev[j] = j; // for i=0 and for any 'j'.
    }

    for(int i=1;i<=n;i++)
    {
        cur[0] = i; // for j=0 and for any 'i'.
        for(int j=1;j<=m;j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                cur[j] = prev[j - 1];
            }
            else
            {
                cur[j] = 1 + min(cur[j - 1], min(prev[j], prev[j - 1]));
                // insertions -> cur[j - 1], stay on 'i' means 'cur', 
                //            and add hypothetically a character at 'i+1' and move to 'j-1'.
                // deletion -> prev[j], move to next 'i'(i-1) means 'prev',
                //            and delete element at 'i' But stay on 'j' for next comparison. 
                //            
                // replace -> prev[j - 1], move to next 'i'(i-1) means 'prev',
                //            and replace it to t[j],
                //            Now, by replacing it become equal so move 'j'(j-1).
            }
        }
        prev = cur;
    }

    cout << prev[m] << endl;

    return 0;
}