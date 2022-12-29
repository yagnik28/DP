#include <bits/stdc++.h>
using namespace std;

/* Recursion :
   T.C => O(Exponential)
   S.C => O(N)
*/

// Memoization
// T.C => O(N*K)
// S.C => O(N) + O(N)

int f(int i, int k, vector<int> arr, vector<int> &dp)
{
    int n = arr.size();
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int len = 0, mx = 0, mx_ans = 0;
    for (int j = i; j <= min(n - 1, (i + k - 1)); j++)
    {
        len++;
        mx = max(mx, arr[j]);
        int sum = (len * mx) + f(j + 1, k, arr, dp);
        mx_ans = max(mx_ans, sum);
    }
    return dp[i] = mx_ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n, -1);
    cout << f(0, k, arr, dp) << endl;

    return 0;
}