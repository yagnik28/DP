#include<bits/stdc++.h>
using namespace std;

/*
    Recusrion : 
    T.C => O((3^N)*(3^N))
    S.C => O(N)
*/

// Memoization : 
// T.C => O(N*M*M*9)
// S.C => O(N*M*M) + O(N) 

const int MINIMUM = -1e8;

/*
    f(i1, j1) -> Alice, f(i2, j2) -> Bob => Alice and Bob will run together,
    means both will be on same row everytime so i1 = i1, -> i1 = i2 = i.
    4D DP -> 3D DP conversion
*/

int max_chocalate(int i, int j1, int j2, vector<vector<int>> &a, vector<vector<vector<int>>> &dp)
{
    int n = a.size();
    int m = a[0].size();
    // edge case for going out of boundary.
    if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
    {
        return MINIMUM;
    }
    if(i == n-1)
    {
        if(j1 == j2)
        {
            return a[i][j1];
        }
        else
        {
            return a[i][j1] + a[i][j2];
        }
    }
    if(dp[i][j1][j2] != (-1))
    {
        return dp[i][j1][j2];
    }
    int mx = MINIMUM;
    // for all 9 paths, -> for 1 path of Alice there is 3 paths for Bob like that 3*3 = 9 total paths.
    for(int dj1 = -1 ; dj1 <= 1; dj1++)
    {
        for(int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if(j1 == j2) 
            {
                value = a[i][j1];
            }
            else
            {
                value = a[i][j1] + a[i][j2];
            }
            value += max_chocalate(i + 1, j1 + dj1, j2 + dj2, a, dp);

            mx = max(mx, value);
        }
    }
    return dp[i][j1][j2] = mx;
}


int main()
{
    int n, m;
    cin >> n >> m; // n -> rows, m -> coumns.
    vector<vector<int>> a(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
    cout << max_chocalate(0, 0, m-1, a, dp) << endl;

    return 0;
}

/*
    TESTCASE : 
        3 4
        2 3 1 2
        3 4 2 2 
        5 6 3 5
    ANS : 
        21
*/