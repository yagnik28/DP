#include <bits/stdc++.h>
using namespace std;

// Tabulation : 
// T.C => O(C*C*C)
// S.C => O(C*C)

int main()
{
    int n, c; // n -> length of stick, c -> size of array(number of indexing given)
    cin >> n >> c;
    vector<int> cuts(c);
    for (int i = 0; i < c; i++)
    {
        cin >> cuts[i];
    }
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    // now size of array increased to 'c+2' after adding '0' and 'n'.
    // now, first index is '0' and last index if 'c+1'
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
    // base case
    // (i > j) => return 0;
    for (int j = 0; j <= c; j++)
    {
        for (int i = j + 1; i <= c + 1; i++)
        {
            dp[i][j] = 0;
        }
    }

    // array index range => [0, c+1]
    // excluding 0 & n range => [1, c]

    // for finding f(i, ind-1) => for i=0 and ind=i, ind-1 = (-1)
    // that'why we are  excluding i=0 and starting from i=1.

    // for f(ind+1, j) => for j=c+1 and ind=j, ind+1 = c+2 out of array
    // that's why we are excluding j=c+1 and end up at j=c.

    for (int i = c + 1; i >= 1; i--)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i > j)
            {
                continue;
            }
            int mn = 1e9;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mn = min(mn, cost);
            }
            dp[i][j] = mn;
        }
    }
    cout << dp[1][c] << endl; 

    return 0;
}