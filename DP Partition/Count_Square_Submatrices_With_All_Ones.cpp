#include <bits/stdc++.h>
using namespace std;

// T.C => O(N*M)
// S.C => O(N*M)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // for every 1st column and 1st row it is same as matrix.
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += dp[i][j];
        }
    }
    cout << sum << endl;

    return 0;
}