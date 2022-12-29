#include<bits/stdc++.h>
using namespace std;

// T.C => O(N*N) => O((N*(N+1))/2) => O(1 + 2 + ... + N)
// S.C => O(N) 

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> next(n, -1);

    // Instead of dp[i+1][j] OR dp[i+1][j+1] we used next[j] OR next[j+1],
    // means we only need the next row only so we kept it with us as 'next' array.

    // BASE CASE
        for(int j=0;j<n;j++)
        {
            next[j] = a[n-1][j];
        }

    vector<int> cur(n);

    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down = a[i][j] + next[j]; // i = n-2, i+1 = n-1 means for dp[i][j] it uses dp[i+1][j],
                                             // means for dp[n-2][j] uses dp[n-1][j]
            int diagonal = a[i][j] + next[j+1]; // same here as above 
            cur[j] = min(down, diagonal);
        }
        next = cur;
    }
    cout << next[0] << endl;

    return 0;
}

/* Without Using extra 'cur' Array.
    // BASE CASE
        for(int j=0;j<n;j++)
        {
            next[j] = a[n-1][j];
        }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down = a[i][j] + next[j]; // i = n-2, i+1 = n-1 means for dp[i][j] it uses dp[i+1][j],
                                             // means for dp[n-2][j] uses dp[n-1][j]
            int diagonal = a[i][j] + next[j+1]; // same here as above 
            next[j] = min(down, diagonal);
        }
    }
    cout << next[0] << endl;
*/

/*
    TESTCASE : 
        4
        1
        2 3
        3 6 7
        8 9 6 10
    ANS : 
        14
*/