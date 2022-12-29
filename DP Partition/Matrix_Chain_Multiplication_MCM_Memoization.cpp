#include <bits/stdc++.h>
using namespace std;

/* Recursion :
   T.C => O(Exponential)
   S.C => O(N)
*/

// Memoization
// T.C => O(N*N*N) -> (1 more 'N' for the for loop of 'k')
// S.C => O(N*N) + O(N)

int f(int i, int j, vector<int> a, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0; // operations required is 0 for only 1 matrix to multiply.
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mn = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = a[i - 1] * a[k] * a[j] + f(i, k, a, dp) + f(k + 1, j, a, dp);
        // 'k' is till 'j-1' because we have f(k+1, j)
        // so for k='j' -> k+1=;j+1 that's out of bound.
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f(1, n - 1, arr, dp) << endl;

    return 0;
}