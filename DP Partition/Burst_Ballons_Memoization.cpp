#include <bits/stdc++.h>
using namespace std;

/* Recursion :
   T.C => O(Exponential)
   S.C => O(N)
*/

// Memoization
// T.C => O(N*N*N)
// S.C => O(N*N) + O(N)

int f(int i, int j, vector<int> nums, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mx = 0;
    for (int ind = i; ind <= j; ind++)
    {
        int coins = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1, nums, dp) + f(ind + 1, j, nums, dp);
        mx = max(mx, coins);
    }
    return dp[i][j] = mx;
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
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << f(1, n, nums, dp) << endl;

    return 0;
}