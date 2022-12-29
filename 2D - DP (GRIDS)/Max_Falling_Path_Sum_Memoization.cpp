#include<bits/stdc++.h>
using namespace std;

/* Recusrsion : 
    T.C => O(3^N)
    S.C => O(N)
*/

// Memoization : 
// T.C => O(N*M)
// S.C => O(N) -> Recursion + O(N*M) -> DP Array.

const int MINIMUM = -1e8;

int max_falling_sum(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    int n = a.size();
    int m = a[0].size();
    if(i == 0)
    {
        return a[0][j];
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }

    int up = a[i][j] + max_falling_sum(i-1, j, a, dp);
    int left_diagonal, right_diagonal;

        if((j-1) >= 0)
        {
            left_diagonal = a[i][j] + max_falling_sum(i-1, j-1, a, dp);
        }
        else
        {
            left_diagonal = a[i][j] + MINIMUM;
        }

        if((j+1) < m)
        {
            right_diagonal = a[i][j] + max_falling_sum(i-1, j+1, a, dp);
        }
        else
        {
            right_diagonal = a[i][j] + MINIMUM;
        }

    return dp[i][j] = max(up, max(left_diagonal, right_diagonal));

}

int main()
{
    int n, m; // n -> rows, m -> columns.
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n ,vector<int> (m, -1));

    int mx = max_falling_sum(n-1, 0, a, dp);
    for(int j=1;j<m;j++)
    {
        mx = max(mx, max_falling_sum(n-1, j, a, dp));
    }
    cout << mx << endl;


    return 0;
}

/*
    TESTCASE : 
        4 4
        1 2 10 4
        100 3 2 1
        1 1 20 2
        1 2 2 1
    ANS : 
        105
*/