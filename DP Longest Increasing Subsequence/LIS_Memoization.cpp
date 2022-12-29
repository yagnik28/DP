#include <bits/stdc++.h>
using namespace std;

/* Recursion : 
T.C => O(2^N)
S.C => O(N)
*/

// Memoization
// T.C => O(N*N)
// S.C => O(N*N) + O(N)

int f(int i, int prev_i, vector<int> nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (i == n)
    {
        return 0;
    }
    if (dp[i][prev_i + 1] != -1)
    {
        return dp[i][prev_i + 1];
    }

    int take = 0;
    if (prev_i == -1 || nums[i] > nums[prev_i])
    {
        take = 1 + f(i + 1, i, nums, dp);
    }
    int not_take = 0 + f(i + 1, prev_i, nums, dp);
    return dp[i][prev_i + 1] = max(take, not_take);
    // prev_i = -1 for i = 0 so we increased indexing '1' based in dp array
    // where in recursion it's '0' based.
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << f(0, -1, nums, dp) << endl;

    return 0;
}