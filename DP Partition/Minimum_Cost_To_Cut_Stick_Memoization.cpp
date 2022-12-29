#include <bits/stdc++.h>
using namespace std;

/* Recursion :
   T.C => O(Exponential)
   S.C => O(C)
*/

// Memoization
// T.C => O(C*C*C)
// S.C => O(C*C) + O(C)

int f(int i, int j, vector<int> cuts, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mn = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts, dp) + f(ind + 1, j, cuts, dp);
        mn = min(mn, cost);
    }
    return dp[i][j] = mn;
}

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
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    cout << f(1, c, cuts, dp) << endl;

    return 0;
}