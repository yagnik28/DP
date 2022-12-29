#include<bits/stdc++.h>
using namespace std;

/*** FIXED STARTING POINT AND VARIABLE ENDING POINT. ***/

/* HERE, We go from (0, 0) to the last row. because (0, 0) is the only fixed,
   while last row has n-1 value to be destinations. */

// Recursion :
// T.C => O( 2 ^ (N(N+1))/2)
// S.C => O(N)

// Memoization :
// T.C => O(N*N) -> O((N*(N+1))/2) -> O(1 + 2 + .... + N)
// S.C => O(N) + O(N*N)

int min_sum(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    // base case
    int n = a.size();
    if(i == n-1)
    {
        return a[n-1][j];
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }
    int down = a[i][j] + min_sum(i+1, j, a ,dp);
    int diagonal = a[i][j] + min_sum(i+1, j+1, a ,dp);

    return dp[i][j] = min(down, diagonal);
}

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
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout << min_sum(0, 0, a ,dp) << endl;

    return 0;
}

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



/*
const int INF = 1e9;

int min_sum(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
    {
        return a[0][0];
    }
    if(i < 0 || j < 0 || i < j)
    {
        return 0;
    }
    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }
    int up = 0, diagonal = 0;
    if(i > 0)
    {
        up = a[i][j] + min_sum(i - 1, j, a ,dp);
    }
    if(i > 0 && j > 0)
    {
        diagonal = a[i][j] + min_sum(i - 1, j - 1, a ,dp);
    }

    return dp[i][j] = min(up, diagonal);
}

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
    int minimum = INF;
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for(int i=0;i<n;i++)
    {
        minimum = min(minimum, min_sum(n-1, i, a, dp));
    }
    cout << minimum << endl;
    return 0;
}
*/